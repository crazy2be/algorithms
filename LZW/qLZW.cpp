#include "QLZW.h"

#include <string>
#include <vector>

#include <algorithm>

#include "../containerHelpers.h"

using namespace std;

struct CodePair
{
    int code;
    string text;

    bool operator < (const CodePair& other) const
    {
        return text < other.text;
    }
};

vector<int> QLZW::encode(string text)
{
    vector<CodePair> dictionary;

    for(int ix = 0; ix < text.length(); ix++)
    {
        CodePair pair;
        pair.code = text[ix];
        pair.text = text[ix];
        if(!BinaryContains(dictionary, pair))
            InsertSorted(dictionary, pair);
    }

    vector<int> encodedValues;

    int curCodePair = 128;
    string lastEncodedText;
    for(int ix = 0; ix < text.length();)
    {
        //See how much we can satisfy with our dictionary
        string curEncoded;
        CodePair curPair;
        while(ix < text.length())
        {
            curPair.text += text[ix];
            
            if(!BinaryContains(dictionary, curPair))
            {
                curPair.text = curPair.text.substr(0, curPair.text.size() - 1);
                break;
            }

            ix++;

            //To update the code number
            curPair = FindSorted(dictionary, curPair);
        }

        encodedValues.push_back(curPair.code);

        //Add last text encoded plus first char of text we encoded now to the dictionary
        CodePair newCodePair;
        newCodePair.text = lastEncodedText + curPair.text[0];

        if(!BinaryContains(dictionary, newCodePair))
        {
            newCodePair.code = curCodePair++;
            InsertSorted(dictionary, newCodePair);
        }

        lastEncodedText = curPair.text;
    }

    return encodedValues;
}

struct _CompareWithCode {
  bool operator() (CodePair i, CodePair j) 
  {
      return i.code < j.code;
  }
} CompareWithCode;

string QLZW::decode(vector<int> codes)
{
    vector<CodePair> dictionary;

    for(int ix = 0; ix < codes.size(); ix++)
    {
        if(codes[ix] >= 128)
            continue;

        CodePair pair;
        pair.code = codes[ix];
        pair.text = (char)codes[ix];
        if(!BinaryContains(dictionary, pair))
            InsertSorted(dictionary, pair);
    }

    string decodedText;

    int curCodePair = 128;
    string lastEncodedText;
    for(int ix = 0; ix < codes.size(); ix++)
    {
        CodePair curPair;
        curPair.code = codes[ix];

        curPair = FindSorted(dictionary, curPair, CompareWithCode);

        decodedText += curPair.text;

        //Add last text encoded plus first char of text we encoded now to the dictionary
        CodePair newCodePair;
        newCodePair.text = lastEncodedText + curPair.text[0];

        if(!BinaryContains(dictionary, newCodePair))
        {
            newCodePair.code = curCodePair++;
            InsertSorted(dictionary, newCodePair, CompareWithCode);
        }

        lastEncodedText = curPair.text;
    }

    return decodedText;
}

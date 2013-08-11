#include "QBWT.h"

#include <string>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

struct CharTuple
{
    char ch;
    int index;
    //As we don't write to this it should only copy a pointer, any efficient
    //string implementation are copy-on-write. So theoretically the compiler should
    //even be able to remove this entirely... probably won't though.
    string text;

    bool operator <(const CharTuple& other) const
    {
        for(int ix = 0; ix < text.length(); ix++)
        {
            if(GetCharOffset(ix) < other.GetCharOffset(ix))
                return true;
            else if(GetCharOffset(ix) > other.GetCharOffset(ix))
                return false;
        }

        //All equal
        return false;
    }

    //offset should be not be < than text.length()
    char GetCharOffset(int offset) const
    {
        return text[(index + offset + text.length()) % text.length()];
    }
};

string QBWT::Compress(string text)
{
    //Last char
    text += "~";

    //Keep track of indicies of characters
    vector<CharTuple> chIndices;
    for(int ix = text.length() - 1; ix >= 0; ix--)
    {
        CharTuple chTuple = {text[ix], ix, text};
        chIndices.push_back(chTuple);
    }

    stable_sort(chIndices.begin(), chIndices.end());

    string result;
    for(int ix = 0; ix < text.length(); ix++)
    {
        result += chIndices[ix].GetCharOffset(-1);
    }

    return result;
}

string QBWT::Decompress(string text)
{
    //Keep track of indicies of characters
    vector<CharTuple> chIndices;
    for(int ix = 0; ix < text.length(); ix++)
    {
        string tempText;
        tempText += text[ix];
        CharTuple chTuple = {text[ix], ix, tempText};
        chIndices.push_back(chTuple);
    }

    stable_sort(chIndices.begin(), chIndices.end());

    //The last character is just a sentinel
    int curIndex = text.length() - 1;

    string realText;

    while(true)
    {
        curIndex = chIndices[curIndex].index;
        if(curIndex == text.length() - 1) //Kinda sloppy
            break;
        realText += chIndices[curIndex].ch;
    }

    return realText;
}
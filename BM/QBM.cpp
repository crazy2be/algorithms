#include "QBM.h"

#include <map>

using namespace std;

vector<int> QBM::Matches(string text, string pattern)
{
    //Straight copy from the slides
    //Last positions for every char
    map<char, int> L;
    for(int ix = 0; ix < pattern.size(); ix++)
        L[pattern[ix]] = ix;

    //The value at an index represents:
    //That the string after the value EQUALS the string after the index,
    //and is maximized. Also the char at the index and value are not the same.
    //Or, if it is negative, it is just index - length + 2?
    vector<int> S;

    //Brute force creation, just to start with...
    for(int ix = 0; ix < pattern.size(); ix++)
    {
        //Need to match everything after position ix to 
        //everything after position iy, while making sure
        //text[ix] != text[iy]
        int iy = ix - 1;
        int match = ix - pattern.size() + 2;
        if(match >= 0) match = -1;
        while(iy >= -1)
        {
            while(iy >= 0 && pattern[iy] == pattern[ix])
            {
                iy--;
            }

            if(iy < -1) break;

            int offset = 1;
            while((ix + offset) < pattern.size() &&
                  (iy + offset) < pattern.size())
            {
                if(pattern[ix + offset] != pattern[iy + offset])
                    break;
                offset++;
            }

            if((ix + offset) == pattern.size() || (iy + offset) == pattern.size())
            {
                match = iy;
                break;
            }
            iy--;
        }

        S.push_back(match);
    }

    int patSize = pattern.size();
    int n = text.size();

    int iText = patSize - 1;
    int iPattern = patSize - 1;

    vector<int> matches;

    while(iText < n && iPattern >= 0)
    {
        if(text[iText] == pattern[iPattern])
        {
            if(iPattern > 0)
            {
                iText--;
                iPattern--;
                continue;
            }
            //A full match, so we just record it then pretend its a failure
            matches.push_back(iText);
        }

        iText = iText + patSize - 1 - min(L[text[iText]], S[iPattern]);
        iPattern = patSize - 1;
    }

    return matches;
}
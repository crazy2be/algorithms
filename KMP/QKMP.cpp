#include "QKMP.h"

#include <vector>
#include <string>

using namespace std;

vector<int> QKMP::Matches(string text, string pattern)
{
    //F[j] is the length of the largest prefix of P(0, j) that is a suffix of P(1, j)
    vector<int> F;
    for(int ix = 0; ix < pattern.size(); ix++)
        F.push_back(0);
    int matchPos = 0;
    for(int failurePos = 1; failurePos < pattern.size(); failurePos++)
    {
        //Go back in failure array until we figure out the match size
        while(matchPos > 0 && pattern[failurePos] != pattern[matchPos])
            matchPos = F[matchPos - 1];

        if(pattern[failurePos] == pattern[matchPos])
            matchPos++;

        F[failurePos] = matchPos;
    }

    vector<int> matches;
    matchPos = 0;
    for(int textPos = 0; textPos < text.size(); textPos++)
    {
        if(text[textPos] == pattern[matchPos])
        {
            matchPos++;
            if(matchPos == pattern.length())
            {
                matches.push_back(textPos - matchPos + 1);

                //Essentially the end of the string fails to match
                matchPos = F[matchPos - 1];
            }
        }
        else
        {
            //Ugh... we need to test this char again
            if(matchPos > 0) textPos--;

            //Follow failure array until it matches
            while(matchPos > 0 && text[textPos] != pattern[matchPos])
                matchPos = F[matchPos - 1];
        }
    }

    return matches;
}

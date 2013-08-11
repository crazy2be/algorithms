#include "QKMP.h"

#include <vector>
#include <string>

using namespace std;

vector<int> QKMP::Matches(string text, string pattern)
{
    //Really don't need this awful 2D structure, but its how they explained it so they
    //could very well ask us to fill one of these out.

    //x, y... not row, column, as x, y makes more sense...
    vector<char> arr[1000];
    for(int ix = 0; ix < 1000; ix++)
        for(int iy = 0; iy < text.size(); iy++)
            arr[ix].push_back(' ');

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
            //Follow failure array until it matches
            while(matchPos > 0 && text[textPos] != pattern[matchPos])
                matchPos = F[matchPos - 1];
        }
    }
    /*
    //Just an exact copy off the slides
    int i = 0;
    int j = 0;
    while(i < text.size())
    {
        if(text[i] == pattern[j])
        {
            if(j == pattern.size() - 1)
            {
                matches.push_back(i - j);
                if(j > 0)
                {
                    j = F[j - 1];
                }
                else
                {
                    i++;
                }
            }
            else
            {
                i++;
                j++;
            }
        }
        else
        {
            if(j > 0)
            {
                j = F[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    */

    return matches;
}

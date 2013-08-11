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

    //Just an exact copy of the given algorithm on the slides,
    //F[j] is the length of the largest prefix of P(0, j) that is a suffix of P(1, j)
    vector<int> F;
    for(int ix = 0; ix < pattern.size(); ix++)
        F.push_back(0);
    int i = 1;
    int j = 0;
    while(i < pattern.size())
    {
        if(pattern[i] == pattern[j])
        {
            F[i] = j + 1;
            i++;
            j++;
        }
        else if(j > 0)
        {
            j = F[j - 1];
        }
        else
        {
            F[i] = 0;
            i++;
        }
    }

    vector<int> matches;
    //Just an exact copy off the slides
    i = 0;
    j = 0;
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

    return matches;
}

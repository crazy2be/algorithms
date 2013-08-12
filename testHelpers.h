#pragma once

#include <string>
#include <vector>

#include <math.h>

//Not true random, but for testing this is better
int random(int min, int max)
{
    //Skewed to low numbers, approximately exponential?
    int range = max - min;
    int maxRangeBit = ceil(log((double)range) / log((double)2));
    int maxBit = rand() % (maxRangeBit + 1);

    int realRange = std::min((int)pow(2, (double)maxBit), range);

    return rand() % realRange + min;
}

std::string GenStringRandom(int stringSize = -1)
{
    std::vector<char> fullAlphabet;
    for(int ix = 33; ix < 126; ix++)
        fullAlphabet.push_back((char)ix);

    int alphabetSize = random(2, fullAlphabet.size());
    std::vector<char> alphabet;

    while(alphabetSize --> 0)
    {
        int iFullAlpha = random(0, fullAlphabet.size());
        char ch = fullAlphabet[iFullAlpha];
        fullAlphabet.erase(fullAlphabet.begin() + iFullAlpha);
        alphabet.push_back(ch);
    }

    std::string randString;

    if(stringSize == -1)
        stringSize = random(2, 100);
    while(stringSize --> 0)
    {
        randString += alphabet[random(0, alphabet.size())];
    }

    return randString;
}
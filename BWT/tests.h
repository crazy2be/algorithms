#pragma once

#include "interface.h"

#include <string>
#include <cstdlib>
#include <vector>

#include "../DASSERT.h"

int random(int min, int max)
{
    return rand() % (max - min) + min;
}

std::string GenStringRandom()
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

    int stringSize = random(2, 100);
    while(stringSize --> 0)
    {
        randString += alphabet[random(0, alphabet.size())];
    }

    return randString;
}

void TestBWT(IBWT* bwt)
{
    for(int ix = 0; ix < 1000; ix++)
    {
        std::string realText = GenStringRandom();
        std::string compText = bwt->Compress(realText);
        std::string decompText = bwt->Decompress(compText);

        DASSERT(realText == decompText);
    }
}
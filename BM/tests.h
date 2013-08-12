#include "BM.h"

#include <vector>

#include "../DASSERT.h"

#include "../testHelpers.h"



void TestBM(IFindMatches* matcher)
{
    std::vector<int> matches;

    matches = matcher->Matches("ababcacccabcabca", "abca");
    DASSERT(matches[0] == 2);
    DASSERT(matches[1] == 9);
    DASSERT(matches[2] == 12);

    matches = matcher->Matches("boboobonobobo", "bonobobo");
    DASSERT(matches[0] == 5);

    matches = matcher->Matches("abaxyabacabbaababacaba", "abacaba");
    DASSERT(matches[0] == 15);

    //Should really make a generic vector comparator.
    matches = matcher->Matches("ababa", "aba");
    DASSERT(matches[0] == 0);
    DASSERT(matches[1] == 2);

    matches = matcher->Matches("aababaabaababaabaa", "aababaabaa");
    DASSERT(matches[0] == 0);
    DASSERT(matches[1] == 8);
}

void TestBM(IFindMatches* alg1, IFindMatches* alg2)
{
    int testCount = 1000;

    while(testCount --> 0)
    {
        std::string pattern = GenStringRandom(random(2, 5));
        std::string text = GenStringRandom(random(2, 50));

        std::vector<int> matches1 = alg1->Matches(text, pattern);
        std::vector<int> matches2 = alg2->Matches(text, pattern);
        DASSERT(matches1.size() == matches2.size());
        for(int ix = 0; ix < matches1.size(); ix++)
            DASSERT(matches1[ix] == matches2[ix]);
    }
}
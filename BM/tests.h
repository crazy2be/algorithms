#include "BM.h"

#include <vector>

#include "../DASSERT.h"

void TestBM(IBM* bm)
{
    std::vector<int> matches;

    matches = bm->Matches("ababcacccabcabca", "abca");
    DASSERT(matches[0] == 2);
    DASSERT(matches[1] == 9);
    DASSERT(matches[2] == 12);

    matches = bm->Matches("boboobonobobo", "bonobobo");
    DASSERT(matches[0] == 5);

    matches = bm->Matches("abaxyabacabbaababacaba", "abacaba");
    DASSERT(matches[0] == 15);

    //Should really make a generic vector comparator.
    matches = bm->Matches("ababa", "aba");
    DASSERT(matches[0] == 0);
    DASSERT(matches[1] == 2);

    matches = bm->Matches("aababaabaababaabaa", "aababaabaa");
    DASSERT(matches[0] == 0);
    DASSERT(matches[1] == 8);
}
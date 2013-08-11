#include "KMP.h"

#include <vector>

#include "../DASSERT.h"

void TestKMP(IKMP* kmp)
{
    std::vector<int> matches = kmp->Matches("abaxyabacabbaababacaba", "abacaba");
    DASSERT(matches[0] == 15);

    //Should really make a generic vector comparator.
    matches = kmp->Matches("ababa", "aba");
    DASSERT(matches[0] == 0);
    DASSERT(matches[1] == 2);
}
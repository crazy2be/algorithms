#pragma once

#include "interface.h"

#include <string>
#include <cstdlib>
#include <vector>

#include "../DASSERT.h"

#include "../testHelpers.h"

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
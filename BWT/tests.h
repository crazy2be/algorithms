#pragma once

#include "qImpl.h"

#include <string>

void GenStringsRandom()
{

}

void TestBWT()
{
    QBWT q;
    std::string result = q.Compress("BANANA");
    std::string banana = q.Decompress(result);
}
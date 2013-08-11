#pragma once

#include <string>

class IBWT
{
public:
    std::string Compress(std::string);
    std::string Decompress(std::string);
};
#pragma once

#include <string>

class IBWT
{
public:
    virtual std::string Compress(std::string) = 0;
    virtual std::string Decompress(std::string) = 0;

    virtual ~IBWT() { }
};
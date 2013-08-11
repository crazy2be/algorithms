#pragma once

#include "interface.h"

#include <string>

class QBWT : public IBWT
{
public:
    virtual std::string Compress(std::string);
    virtual std::string Decompress(std::string);
};
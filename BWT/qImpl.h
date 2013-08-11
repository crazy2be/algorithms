#pragma once

#include "interface.h"

class QBWT : public IBWT
{
public:
    std::string Compress(std::string) override;
    std::string Decompress(std::string) override;
};
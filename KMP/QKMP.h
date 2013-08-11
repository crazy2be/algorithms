#pragma once

#include "KMP.h"

class QKMP : public IKMP
{
public:
    virtual std::vector<int> Matches(std::string text, std::string pattern);
};
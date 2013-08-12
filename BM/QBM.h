#pragma once

#include "BM.h"

class QBM : public IBM
{
public:
    virtual std::vector<int> Matches(std::string text, std::string pattern);
};
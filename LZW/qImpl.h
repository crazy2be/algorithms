#pragma once

#include "LZW.h"
#include <string>

class QLZW : public LZW
{
public:
    virtual vector<int> encode(string);
    virtual string decode(vector<int>);
};
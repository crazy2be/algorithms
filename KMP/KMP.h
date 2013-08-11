#pragma once

#include <vector>
#include <string>

class IKMP
{
public:
    virtual ~IKMP() { }
    virtual std::vector<int> Matches(std::string text, std::string pattern) = 0;
};
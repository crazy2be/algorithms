#pragma once

#include <vector>
#include <string>

class IBM
{
    public:
    virtual ~IBM() { }
    virtual std::vector<int> Matches(std::string text, std::string pattern) = 0;
};
#pragma once

#include <vector>
#include <string>

class IFindMatches
{
public:
    virtual ~IFindMatches() { }
    virtual std::vector<int> Matches(std::string text, std::string pattern) = 0;
};

class IKMP : public IFindMatches
{
};
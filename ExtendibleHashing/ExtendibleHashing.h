#pragma once

class IExtHash
{
public:
    virtual ~IExtHash() { }

    virtual void SetMin(int) = 0;
    virtual void SetMax(int) = 0;

    virtual void Insert(int) = 0;
    virtual void Delete(int) = 0;
    virtual bool Contains(int) = 0;
};
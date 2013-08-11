#pragma once

#include <iostream>

#ifndef _MSC_VER
#define DASSERT(condition)                              \
if(!(condition))                                        \
{                                                       \
    printf("Condition failed: %s\n", #condition);       \
    throw "Assert failed: " #condition;                 \
}                                                       
#else
#define DASSERT(condition)                              \
if(!(condition))                                        \
{                                                       \
    printf("Condition failed: %s\n", #condition);       \
    __debugbreak();                                     \
    throw "Assert failed: " #condition;                 \
}                                                       
#endif
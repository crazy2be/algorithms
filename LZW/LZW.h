#pragma once
#include "../util/includes.h"

class LZW {
public:
	LZW() {}
	virtual ~LZW() {}
	virtual vector<int> encode(string) = 0;
	virtual string decode(vector<int>) = 0;
};

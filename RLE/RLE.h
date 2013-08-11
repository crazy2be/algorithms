#pragma once
#include "../util/includes.h"

class RLE {
public:
	RLE() {}
	virtual ~RLE() {}
	virtual vector<bool> encode(vector<bool>) = 0;
	virtual vector<bool> decode(vector<bool>) = 0;
};

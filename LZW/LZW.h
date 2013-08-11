#pragma once
#include <string>

using std::string;

class LZW {
public:
	LZW();
	virtual ~LZW();
	virtual string encode(string) = 0;
	virtual string decode(string) = 0;
}

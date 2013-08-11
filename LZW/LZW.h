#pragma once
#include <string>
#include <map>

using std::string;
using std::map;

class LZW {
public:
	LZW();
	virtual ~LZW();
	virtual string encode(string) = 0;
	virtual string decode(string) = 0;
}

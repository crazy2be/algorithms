#pragma once
#include <string>
#include <map>
#include <vector>
#include <iostream>

using std::string;
using std::map;
using std::vector;
using std::cout;
using std::endl;

class LZW {
public:
	LZW() {}
	virtual ~LZW() {}
	virtual vector<int> encode(string) = 0;
	virtual string decode(vector<int>) = 0;
};

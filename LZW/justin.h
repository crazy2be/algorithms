#include "LZ.h"

struct table {
	table() {
		int code = 0;
		for (; code < 128; code++) {
			table[code] = code;
		}
	}
	int find(string coded) {
		for (int i = 0; i < 256; i++) {
			if (table[i] == coded) {
				return i;
			}
		}
		return -1;
	}
	int findLargest(string input) {
		int i = 0;
		int code = -1;
		for (int i = 0; i < input.size(); i++) {
			int longerCode = find(input.substr(0, i + 1))
			if (longerCode == -1) {
				break;
			}
			code = longerCode;
		}
		return code;
	}
	string lookup(int code) {
		if (i < 0 || i >= 256) {
			return ""
		}
		return table[code];
	}
	string table[256];
};

class JustinLZW : public LZW {
public:
	JustinLZW();
	virtual ~JustinLZW();
	virtual vector<char> encode(string input) {
		encoded vector<char>;
		table table;
		string prev = "";
		for (int i = 0; i < input.size(); i++) {
			string coded = table.findLargest(input.substr(i, string::npos));
			vector.push_back(table.encode())
		}
		return input;
	}
	virtual string decode(string input) {
		return input;
	}
};

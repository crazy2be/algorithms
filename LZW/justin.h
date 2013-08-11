struct table {
	table() {
		topCode = 0;
		for (; topCode < 128; topCode++) {
			mapping[topCode] = topCode;
		}
	}
	int find(string coded) {
		for (int i = 0; i < 256; i++) {
			if (mapping[i] == coded) {
				return i;
			}
		}
		return -1;
	}
	int findLargest(string input) {
		int i = 0;
		int code = -1;
		for (int i = 0; i < input.size(); i++) {
			int longerCode = find(input.substr(0, i + 1));
			if (longerCode == -1) {
				break;
			}
			code = longerCode;
		}
		return code;
	}
	string lookup(int code) {
		if (code < 0 || code >= 256) {
			return "";
		}
		return mapping[code];
	}
	void add(string str) {
		mapping[topCode] = str;
		topCode++;
	}
	int topCode;
	string mapping[256];
};

class JustinLZW : public LZW {
public:
	JustinLZW() {}
	virtual ~JustinLZW() {}
	virtual vector<int> encode(string input) {
		table table;
		vector<int> encoded;
		string prev = "";
		int offset = 0;
		while (offset < input.size()) {
			string remaining = input.substr(offset, string::npos);
			int code = table.findLargest(remaining);
			encoded.push_back(code);

			string str = table.lookup(code);
			if (offset > 0) {
				table.add(prev + str.substr(0, 1));
			}
			prev = str;
			offset += str.size();
		}
		return encoded;
	}
	virtual string decode(vector<int> input) {
		table table;
		string decoded;
		string prev = "";
		for (int i = 0; i < input.size(); i++) {
			int code = input[i];
			string str = table.lookup(code);
			if (i > 0) {
				table.add(prev + str.substr(0, 1));
			}
			prev = str;
			decoded += str;
		}
		return decoded;
	}
};

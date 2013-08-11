#include <cmath>

typedef vector<bool>::iterator iter;

class JustinRLE : public RLE {
public:
	JustinRLE() {};
	virtual ~JustinRLE() {};
	virtual vector<bool> encode(vector<bool> decoded) {
		vector<bool> encoded;
		bool bit = decoded[0];
		encoded.push_back(bit);
		int offset = 0;
		while (offset < decoded.size()) {
			int len = findLongest(decoded.begin() + offset, decoded.end());
			encodeInt(encoded, len);
			offset += len;
			cout << len << " " << offset << " " << encoded << endl;
		}
		return encoded;
	}
	int findLongest(iter start, iter end) {
		bool first = *start;
		int len = 0;
		for (; start != end; start++) {
			if (*start == first) len++;
			else break;
		}
		return len;
	}
	int log2(int n) {
		return int(log(double(n)) / log(2));
	}
	void encodeInt(vector<bool>& to, int n) {
		int len = log2(n);
		for (int i = 0; i < len; i++) {
			to.push_back(false);
		}
		for (int i = 0; i <= len; i++) {
			to.push_back(bool(n & (1 << (len - i))));
		}
	}
	void decodeInt(iter start, iter end, int& readLen, int& result) {
		int len = 1;
		readLen = 0;
		while (*start == 0) {
			len++; start++; readLen++;
		}
		result = 0;
		for (int i = 0; i < len; i++) {
			cout << result << " " << *start << " " << i << endl;
			result <<= 1;
			result |= int(*start);
			start++;
			readLen++;
		}
	}
	virtual vector<bool> decode(vector<bool> encoded) {
		vector<bool> decoded;
		bool bit = encoded[0];
		int offset = 1;
		while (offset < encoded.size()) {
			int readLen = -1, runLen = -1;
			decodeInt(encoded.begin() + offset, encoded.end(), readLen, runLen);
			for (int i = 0; i < runLen; i++) {
				decoded.push_back(bit);
			}
			bit = !bit;
			offset += readLen;
			cout << bit << " " << readLen << " " << offset << " " << runLen << " " << decoded << endl;
		}
		return decoded;
	}

private:
};

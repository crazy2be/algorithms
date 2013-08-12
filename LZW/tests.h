#include "../util/prettyprint.hpp"
#include "../util/tests.h"

#include "LZW.h"

void TestLZW(LZW* lzw)
{
	string input = "YO! YOU! YOUR YOYO!";
	int outputChars[13] = {89, 79, 33, 32, 128, 85, 130, 132, 82, 131, 79, 128, 33};
	vector<int> output(outputChars, outputChars + 13);

	vector<int> result = lzw->encode(input);
	MUST_EQUAL(output, result);

	string result2 = lzw->decode(output);
	MUST_EQUAL(input, result2);

	cout << lzw->encode("ababbaabbbaaaba") << endl;
}

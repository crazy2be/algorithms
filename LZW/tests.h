#include "LZW.h"
#include "justin.h"
#include <cassert>

#define MUST_EQUAL(expected, result) \
	if (expected != result) { \
		std::cout << "ERROR: Expected " << endl << expected \
			<< endl << " got " << endl << result << endl; \
		return; \
	}

void TestLZW()
{
	JustinLZW j;
	string input = "YO! YOU! YOUR YOYO!";
	int outputChars[13] = {89, 79, 33, 32, 128, 85, 130, 132, 82, 131, 79, 128, 33};
	vector<int> output(outputChars, outputChars + 13);

	vector<int> result = j.encode(input);
	MUST_EQUAL(output, result);

	string result2 = j.decode(output);
	MUST_EQUAL(input, result2);
}

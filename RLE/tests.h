#include "../util/tests.h"

#include "RLE.h"
#include "justin.h"

vector<bool> bitstring(string bits) {
	vector<bool> result;
	for (int i = 0; i < bits.size() ; i++) {
		if (bits[i] == '0') {
			result.push_back(false);
		} else {
			result.push_back(true);
		}
	}
	return result;
}

void TestRLE()
{
	JustinRLE j;
	vector<bool> input = bitstring("11111110010000000000000000000011111111111");
	vector<bool> output = bitstring("10011101010000101000001011");

	vector<bool> givenOutput = j.encode(input);
	MUST_EQUAL(output, givenOutput);

	vector<bool> givenInput = j.decode(output);
	MUST_EQUAL(input, givenInput);
}

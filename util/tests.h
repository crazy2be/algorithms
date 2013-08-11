#pragma once
#include "prettyprint.hpp"

#define MUST_EQUAL(expected, result) \
	if (expected != result) { \
		std::cout << "ERROR: Expected " << endl << expected \
			<< endl << " got " << endl << result << endl; \
		return; \
	}

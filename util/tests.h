#pragma once
#include "prettyprint.hpp"

#include "../DASSERT.h"

#ifndef _MSC_VER
#define MUST_EQUAL(expected, result) \
	if (expected != result) { \
		std::cout << "ERROR: Expected " << endl << expected \
			<< endl << " got " << endl << result << endl; \
		return; \
	}
#else
#define MUST_EQUAL(expected, result) DASSERT(expected == result)
#endif
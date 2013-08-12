#pragma once
#include "prettyprint.hpp"

// - apt-get install libdw-dev ...
// - g++/clang++ -ldw ...
#define BACKWARD_HAS_DW 1

// - apt-get install binutils-dev ...
// - g++/clang++ -lbfd ...
#define BACKWARD_HAS_BFD 1

#include "backward.hpp"

namespace backward {

	backward::SignalHandling sh;

} // namespace backward

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

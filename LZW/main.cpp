#include "tests.h"

#include "justin.h"
#include "qImpl.h"

int main() {
    JustinLZW jLZW;
	TestLZW(&jLZW);

    QLZW qLZW;
	TestLZW(&qLZW);
}

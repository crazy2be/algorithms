#include "tests.h"

#include "justin.h"
#include "QLZW.h"

int main() {
    JustinLZW jLZW;
	TestLZW(&jLZW);

    QLZW qLZW;
	TestLZW(&qLZW);
}

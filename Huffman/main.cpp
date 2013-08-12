#include "tests.h"

#include "justin.h"

int main() {
	try {
		JustinHuffman jHuffman;
		TestHuffman(jHuffman);
	} catch (string& err) {
		cout << "FATAL ERROR: " << err << endl;
	}
}

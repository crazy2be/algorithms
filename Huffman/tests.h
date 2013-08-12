#include "../util/prettyprint.hpp"
#include "../util/tests.h"

#include "Huffman.h"

vector<bool> bitstring(string input) {
	vector<bool> result;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '0') {
			result.push_back(false);
		} else {
			result.push_back(true);
		}
	}
	return result;
}

void TestHuffman(Huffman& huffman) {
	string input = "LOSSLESS";
	vector<bool> output = bitstring("01001110100011");
	HuffmanTree* tree = new HuffmanTree(
		new HuffmanTree(
			new HuffmanTree(
				new HuffmanTree('E'),
				new HuffmanTree('O')
			),
			new HuffmanTree('L')
		),
		new HuffmanTree('S')
	);

	HuffmanTree* actualTree = huffman.buildTree(input);
	MUST_EQUAL(*tree, *actualTree);

	vector<bool> actualOutput = huffman.encode(tree, input);
	MUST_EQUAL(output, actualOutput);

	string actualInput = huffman.decode(tree, output);
	MUST_EQUAL(input, actualInput);
}

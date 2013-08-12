#pragma once
#include "../util/includes.h"

class HuffmanTree {
public:
	HuffmanTree() : left(NULL), right(NULL), val('\0') {}
	HuffmanTree(char _val) : left(NULL), right(NULL), val(_val) {}
	HuffmanTree(HuffmanTree* _left, HuffmanTree* _right) : left(_left), right(_right), val('\0') {}

	HuffmanTree* left;
	HuffmanTree* right;
	char val;
};

bool operator==(HuffmanTree lhs, HuffmanTree rhs) {
	if (lhs.left == NULL && rhs.left == NULL) return true;
	if (lhs.left == NULL || rhs.left == NULL) return false;

	if (lhs.right == NULL && rhs.right == NULL) return true;
	if (lhs.right == NULL || rhs.right == NULL) return false;

	return (*lhs.left == *rhs.left) &&
		(*lhs.right == *rhs.right) &&
		(lhs.val == rhs.val);
}

bool operator!=(HuffmanTree lhs, HuffmanTree rhs) {
	return !(lhs == rhs);
}

ostream& operator<<(ostream& out, HuffmanTree data) {
	if (data.left != NULL) {
		out << *data.left;
	}
	if (data.right != NULL) {
		out << *data.right;
	}
	return out << data.val;
}

struct HuffmanResult {
	HuffmanResult() : tree(NULL) {}

	HuffmanTree* tree;
	vector<bool> data;
};

class Huffman {
public:
	Huffman() {}
	virtual ~Huffman() {}
	virtual HuffmanTree* buildTree(string) = 0;
	virtual vector<bool> encode(HuffmanTree*, string) = 0;
	virtual string decode(HuffmanTree*, vector<bool>) = 0;
};

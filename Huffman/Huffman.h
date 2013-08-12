#pragma once
#include "../util/includes.h"

class HuffmanTree {
public:
	HuffmanTree() : left(NULL), right(NULL), val('\0') {}
	HuffmanTree(char _val) : left(NULL), right(NULL), val(_val) {}
	HuffmanTree(HuffmanTree* _left, HuffmanTree* _right) : left(_left), right(_right), val('\0') {}

	void print(ostream& out, string prefix) {
		out << prefix << ": " << val << endl;
		if (left != NULL) {
			left->print(out, prefix + "0");
		}
		if (right != NULL) {
			right->print(out, prefix + "1");
		}
	}

	string findCode(string path, char val_) {
		if (val == val_) {
			return path;
		}
		if (left != NULL) {
			string leftPath = left->findCode(path + "0", val_);
			if (leftPath != "") return leftPath;
		}
		if (right != NULL) {
			string rightPath = right->findCode(path + "1", val_);
			if (rightPath != "") return rightPath;
		}
		return "";
	}

	char findVal(string code) {
		if (code == "") {
			return val;
		} else if (code[0] == '0') {
			return left->findVal(code.substr(1, string::npos));
		} else {
			return right->findVal(code.substr(1, string::npos));
		}
	}

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
	data.print(out, "");
	return out;
}

struct HuffmanRoot {
	HuffmanRoot() : tree(NULL), weight(-1) {}
	HuffmanRoot(HuffmanTree* tree_, int weight_) : tree(tree_), weight(weight_) {}

	HuffmanTree* tree;
	int weight;
};

bool operator<(HuffmanRoot lhs, HuffmanRoot rhs) {
	// We want to order trees with a higher weight
	// later in the queue, so we reverse this.
	return lhs.weight > rhs.weight;
}

class Huffman {
public:
	Huffman() {}
	virtual ~Huffman() {}
	virtual HuffmanTree* buildTree(string) = 0;
	virtual vector<bool> encode(HuffmanTree*, string) = 0;
	virtual string decode(HuffmanTree*, vector<bool>) = 0;
};

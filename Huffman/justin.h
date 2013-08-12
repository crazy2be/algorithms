class JustinHuffman : public Huffman {
public:
	JustinHuffman() {};
	virtual ~JustinHuffman() {};
	virtual HuffmanTree* buildTree(string input) {
		return new HuffmanTree();
	}
	virtual vector<bool> encode(HuffmanTree* tree, string input) {

	}
	virtual string decode(HuffmanTree* tree, vector<bool> input) {

	}
};

class JustinHuffman : public Huffman {
public:
	JustinHuffman() {};
	virtual ~JustinHuffman() {};
	virtual HuffmanTree* buildTree(string input) {
		map<char, int> frequencies;
		for (int i = 0; i < input.size(); i++) {
			frequencies[input[i]]++;
		}

		priority_queue<HuffmanRoot> trees;
		for (auto it = frequencies.begin(); it != frequencies.end(); it++) {
			trees.push(HuffmanRoot(new HuffmanTree(it->first), it->second));
		}

		while (trees.size() > 1) {
			HuffmanRoot right = trees.top(); trees.pop();
			HuffmanRoot left = trees.top(); trees.pop();
			trees.push(HuffmanRoot(
				new HuffmanTree(left.tree, right.tree),
				left.weight + right.weight));
		}
		return trees.top().tree;
	}
	virtual vector<bool> encode(HuffmanTree* tree, string input) {
		vector<bool> result;
		for (int i = 0; i < input.size(); i++) {
			string code = tree->findCode("", input[i]);
			if (code == "") {
				throw string("HuffmanTree does not contain code for '") + input[i] + string("'");
			}
			for (int j = 0; j < code.size(); j++) {
				if (code[j] == '0') {
					result.push_back(false);
				} else {
					result.push_back(true);
				}
			}
		}
		return result;
	}
	virtual string decode(HuffmanTree* tree, vector<bool> input) {
		string result;
		int offset = 0;
		while (offset < input.size()) {
			for (int i = 0; i + offset < input.size(); i++) {
				return "";
			}
		}
		return "";
	}
};

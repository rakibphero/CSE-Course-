#include <bits/stdc++.h>

using namespace std;

struct HuffmanNode {
    char data;
    unsigned frequency;
    HuffmanNode* left;
    HuffmanNode* right;

    HuffmanNode(char data, unsigned frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for the priority queue
struct CompareNodes {
    bool operator()(HuffmanNode* lhs, HuffmanNode* rhs) const {
        return lhs->frequency > rhs->frequency;
    }
};

HuffmanNode* buildHuffmanTree(unordered_map<char, double>& probabilities) {
   priority_queue<HuffmanNode*, vector<HuffmanNode*>, CompareNodes> minHeap;

    // Create a leaf node for each character and add it to the min heap
    for (auto& pair : probabilities) {
        minHeap.push(new HuffmanNode(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        // Extract the two nodes with the lowest frequencies
        HuffmanNode* left = minHeap.top();
        minHeap.pop();

        HuffmanNode* right = minHeap.top();
        minHeap.pop();
        // Create a new internal node with a frequency equal to the sum of the children's frequencies
        // and add it to the min heap
        HuffmanNode* internalNode = new HuffmanNode('\0', left->frequency + right->frequency);
        internalNode->left = left;
        internalNode->right = right;
        minHeap.push(internalNode);
    }

    // The remaining node in the min heap is the root of the Huffman tree
    return minHeap.top();
}

// Function to build the Huffman codes and store them in a map
void buildHuffmanCodes(HuffmanNode* root, std::string code, std::unordered_map<char, std::string>& huffmanCodes) {
    if (root) {
        if (!root->left && !root->right) {
            huffmanCodes[root->data] = code;
        }
        buildHuffmanCodes(root->left, code + "1", huffmanCodes);
        buildHuffmanCodes(root->right, code + "0", huffmanCodes);
    }
}

// Function to encode a string using Huffman codes
std::string encodeHuffman(std::string data, std::unordered_map<char, std::string>& huffmanCodes) {
    std::string encodedData = "";
    for (char c : data) {
        encodedData += huffmanCodes[c];
    }
    return encodedData;
}

// Function to decode a string using Huffman codes
std::string decodeHuffman(std::string encodedData, HuffmanNode* root) {
    std::string decodedData = "";
    HuffmanNode* currentNode = root;
    for (char bit : encodedData) {
        if (bit == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
        if (!currentNode->left && !currentNode->right) {
            decodedData += currentNode->data;
            currentNode = root;
        }
    }
    return decodedData;
}

int main() {
    string inputFile = "input.txt";
    string outputFile = "output.txt";

    ifstream inFile(inputFile);
    if (!inFile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    string inputText;
    char c;
    while (inFile.get(c)) {
        inputText += c;
    }
    inFile.close();

    unordered_map<char, double> probabilities;
    probabilities['A'] = 0.45;
    probabilities['B'] = 0.13;
    probabilities['C'] = 0.12;
    probabilities['D'] = 0.16;
    probabilities['E'] = 0.09;
    probabilities['F'] = 0.05;

    HuffmanNode* root = buildHuffmanTree(probabilities);

    unordered_map<char, string> huffmanCodes;
    buildHuffmanCodes(root, "", huffmanCodes);

    string encodedData = encodeHuffman(inputText, huffmanCodes);

    ofstream outFile(outputFile);
    if (!outFile) {
        cerr << "Error opening output file." << endl;
        return 1;
    }
    outFile << encodedData;
    outFile.close();

    // Output the results
    cout << "Original Data: " << inputText << endl;
    cout << "Encoded Data: " << encodedData << endl;

    return 0;
}


//
// Created by n4ssser on 17/11/21.
//

#include "hencoder.h"

hencoder::Node *hencoder::getNode(int ch, int freq, hencoder::Node *left, hencoder::Node *right) {
    Node* node = new Node();
    node->ch = ch;
    node->freq = freq;
    node->left = left;
    node->right = right;
    return node;
}



void hencoder::encode(hencoder::Node *root, string str, unordered_map<int, string> &huffmanCode) {
    if (root == nullptr)
        return;

    // found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->ch] = str;
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}

void hencoder::decode(hencoder::Node *root, int &index, string str) {
    if (root == nullptr) {
        return;
    }
    if (!root->left && !root->right)
    {
        decoded.push_back(root->ch);
        return;
    }

    index++;

    if (str[index] =='0')
        decode(root->left, index, str);
    else
        decode(root->right, index, str);
}

hencoder::hencoder(vector<int> data) {

    for(auto& a : data) {
        freq[a]++;
    }
    priority_queue<Node*, vector<Node*>, comp> pq;
    for (auto pair: freq) {
        pq.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    while (pq.size() != 1)
    {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top();	pq.pop();

        int sum = left->freq + right->freq;
        pq.push(getNode('\0', sum, left, right));
    }

    root = pq.top();

    encode(root, "", huffmanCode);
    for (int ch: data) {
        encoded += huffmanCode[ch];
    }
    int index = -1;
    while (index < (int)encoded.size() - 2) {
        decode(root, index, encoded);
    }

}

bool hencoder::comp::operator()(hencoder::Node *l, hencoder::Node *r) {
    return l->freq > r->freq;
}

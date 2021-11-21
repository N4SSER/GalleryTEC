//
// Created by n4ssser on 17/11/21.
//

#ifndef GALLERYTEC_HENCODER_H
#define GALLERYTEC_HENCODER_H
#include <iostream>
#include <unordered_map>
#include <opencv2/opencv.hpp>
#include <queue>
using namespace std;
using namespace cv;
class hencoder {
private:
    struct Node
    {
        int ch;
        int freq;
        Node *left, *right;
    };
    struct comp
    {
        bool operator()(Node* l, Node* r);
    };
    Node* root;
    Node* getNode(int ch, int freq, Node* left, Node* right);
    unordered_map<int , int> freq;
    unordered_map<int, string> huffmanCode;
    void encode(Node* root, string str,unordered_map<int, string> &huffmanCode);
    void decode(Node* root, int &index, string str);
    void write_h_tree(Node *p, ostream &out);
    void read_h_tree(Node *&p, ifstream &fin);

public:
    string encoded;
    vector<int> decoded;
    hencoder(vector<int> data);


};


#endif //GALLERYTEC_HENCODER_H

#pragma once

class Trie {
private:
    struct Node {
        int key;
        Node** children;

        Node(int key)
            : key(key), children(nullptr) {}

        ~Node() {
            delete[] children;
        }
    };

    Node* root;
    const int n, k;
    const int min, max;
    const int emptyKey; // Key to represent unoccupied node

    int getIndex(int depth, int key) const;
    bool nodeEmpty(Node* node) const;
    bool handleInsert(Node* node, int depth, int key);
    bool handleLookup(Node* node, int depth, int key) const;
    bool handleRemove(Node* node, int depth, int key);
    void handlePrint(Node* node) const;
    Node* findLeftmostLeaf(Node* node) const;
    void clear(Node* node);

public:
    Trie(int n, int k, int min, int max);

    void insert(int key);
    void lookup(int key);
    void remove(int key);
    void print();

    ~Trie();
};
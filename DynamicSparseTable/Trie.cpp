#include "Trie.h"
#include <iostream>

#pragma region Private methods
int Trie::getIndex(int depth, int key) const {
    if (depth == 0) {
        return key % n;
    }

    int div = n;
    for (int i = 1; i < depth; i++) {
        div *= k;
    }

    return (key / div) % k;
}

bool Trie::nodeEmpty(Node* node) const {
    return node->key == emptyKey;
}

bool Trie::handleInsert(Node* node, int depth, int key) {
    if (nodeEmpty(node)) {
        node->key = key;
        return true;
    }
    
    if (node->key == key) {
        return false;
    }

    int size = (node == root) ? n : k;
    if (node->children == nullptr) {
        node->children = new Node * [size]();
    }

    int index = getIndex(depth, key);
    if (node->children[index] == nullptr) {
        node->children[index] = new Node(emptyKey);
    }

    return handleInsert(node->children[index], depth + 1, key);
}

bool Trie::handleLookup(Node* node, int depth, int key) const {
    if (node == nullptr) {
        return false;
    }

    if (node->key == key) {
        return true;
    }

    if (node->children == nullptr) {
        return false;
    }

    int index = getIndex(depth, key);
    return handleLookup(node->children[index], depth + 1, key);
}

bool Trie::handleRemove(Node* node, int depth, int key) {
    if (node == nullptr) {
        return false;
    }

    if (node->key == key) {
        Node* leaf = findLeftmostLeaf(node);
        node->key = leaf->key;
        leaf->key = emptyKey;
        return true;
    }

    if (node->children == nullptr) {
        return false;
    }

    int index = getIndex(depth, key);
    return handleRemove(node->children[index], depth + 1, key);
}

void Trie::handlePrint(Node* node) const {
    if (node == nullptr) {
        return;
    }

    if (!nodeEmpty(node)) {
        printf("%d ", node->key);
    }

    if (node->children != nullptr) {
        int size = (node == root) ? n : k;
        for (int i = 0; i < size; i++) {
            handlePrint(node->children[i]);
        }
    }
}

Trie::Node* Trie::findLeftmostLeaf(Node* node) const {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->children != nullptr) {
        int size = (node == root) ? n : k;
        for (int i = 0; i < size; i++) {
            Node* leaf = findLeftmostLeaf(node->children[i]);
            if (leaf != nullptr) {
                return leaf;
            }
        }
    }

    return nodeEmpty(node) ? nullptr : node;
}

void Trie::clear(Node* node) {
    if (node == nullptr) {
        return;
    }

    if (node->children != nullptr) {
        int size = (node == root) ? n : k;
        for (int i = 0; i < size; i++) {
            clear(node->children[i]);
        }
    }

    delete node;
}
#pragma endregion

#pragma region Public methods
Trie::Trie(int n, int k, int min, int max)
    : root(new Node(min - 1)), n(n), k(k), min(min), max(max), emptyKey(min - 1) {}

void Trie::insert(int key) {
    if (!handleInsert(root, 0, key)) {
        printf("%d exist\n", key);
    }
}

void Trie::lookup(int key) {
    if (handleLookup(root, 0, key)) {
        printf("%d exist\n", key);
    } else {
        printf("%d not exist\n", key);
    }
}

void Trie::remove(int key) {
    if (!handleRemove(root, 0, key)) {
        printf("%d not exist\n", key);
    }
}

void Trie::print() {
    handlePrint(root);
    printf("\n");
}

Trie::~Trie() {
    clear(root);
}
#pragma endregion
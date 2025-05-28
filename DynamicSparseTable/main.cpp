#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Trie.h"

int main() {
    int testCount, min, max, n, k;

    scanf("%d", &testCount);
    scanf("%d %d", &min, &max);
    scanf("%d %d", &n, &k);

    Trie trie(n, k, min, max);

    char cmd;
    int x;
    for (int i = 0; i < testCount; i++) {
        scanf(" %c %d", &cmd, &x);

        switch (cmd) {
            case 'I':
                trie.insert(x);
                break;
            case 'L':
                trie.lookup(x);
                break;
            case 'D':
                trie.remove(x);
                break;
            case 'P':
                trie.print();
                break;
        }
    }
}
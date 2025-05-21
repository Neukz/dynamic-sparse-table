#include <iostream>

int main() {
    int testCount, min, max, n, k;
    std::cin >> testCount >> min >> max >> n >> k;

    char cmd;
    int x;
    for (int i = 0; i < testCount; i++) {
        std::cin >> cmd;
        switch (cmd) {
            case 'I':
                // Insert
                std::cin >> x;
                break;
            case 'L':
                // Lookup
                std::cin >> x;
                break;
            case 'D':
                // Delete
                std::cin >> x;
                break;
            case 'P':
                // Print
                break;
        }
    }
}
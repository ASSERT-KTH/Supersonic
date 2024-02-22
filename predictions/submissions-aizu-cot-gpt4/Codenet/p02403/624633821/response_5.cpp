#include <algorithm>
#include <iostream>
#include <stdio.h>

int main() {
    std::ios_base::sync_with_stdio(false); // make I/O operations faster
    int a = 0, b = 0, H[100], W[100];
    while (1) {
        std::cin >> H[a] >> W[a];
        if (H[a] == 0 && W[a] == 0)
            break;
        a++;
    }
    while (b < a) {
        for (int i = 0; i < H[b]; i++) {
            for (int j = 0; j < W[b]; j++) {
                putchar('#');
            }
            putchar('\n');
        }
        b++;
        putchar('\n');
    }
    return 0;
}
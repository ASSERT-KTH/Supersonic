#include <stdio.h>

int main() {
    int multiplicationTable[10][10];
    
    for(int i = 1; i < 10; ++i) {
        for(int j = 1; j < 10; ++j) {
            multiplicationTable[i][j] = i * j;
        }
    }

    for(int i = 1; i < 10; ++i) {
        for(int j = 1; j < 10; ++j) {
            printf("%dx%d=%d\n", i, j, multiplicationTable[i][j]);
        }
    }
    
    return 0;
}
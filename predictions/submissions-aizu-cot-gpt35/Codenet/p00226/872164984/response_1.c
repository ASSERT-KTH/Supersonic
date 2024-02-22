#include <stdio.h>

#define ARRAY_SIZE 100

int R[ARRAY_SIZE];

int main() {
    char c;
    int h = 0;
    int array_size = ARRAY_SIZE;
    
    for (; read(0, &c, 1);) {
        int i = c;
        int b = 0;
        
        if (i != '\n') {
            b += !!R[i];
            h += !(R[i] ^= 1 << i % 5);
        }
        
        if (++i > 9) {
            for (i = 0; i < array_size; ++i) {
                R[i] = 0;
            }
            printf("%d\n", h);
            printf("%d\n", b - h);
            h = 0;
        }
    }
    
    return 0;
}
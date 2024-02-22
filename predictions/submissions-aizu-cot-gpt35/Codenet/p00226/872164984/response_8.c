#include <stdio.h>

int main() {
    int R[99];
    int i = 0, h = 0, b = 0;
    int c;
    
    // Read characters from input until end of file
    while (read(0, &c, 1)) {
        // Update the values of b and h
        b += !!R[c];
        h += !(R[c] ^= 1 << i % 5);
        
        // Reset the values of R, i, h, and b if i exceeds 9
        if (++i > 9) {
            printf("%d %d\n", h, b - h);
            for (int j = 0; j < 99; ++j) {
                R[j] = 0;
            }
            i = h = b = 0;
        }
    }
    
    return 0;
}
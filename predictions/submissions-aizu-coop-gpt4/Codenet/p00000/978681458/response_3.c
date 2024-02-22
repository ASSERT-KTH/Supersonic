#include <stdio.h>

int main() {
    // Use meaningful variable names
    int multiplier, multiplicand;

    // Use const qualifier for variables that do not change
    const int LIMIT = 10;

    // Create a buffer to store the output
    char buffer[LIMIT*LIMIT*6]; // each entry will be "i*j=k\0"
    char* ptr = buffer;

    for (multiplier = 1; multiplier < LIMIT; multiplier++) {
        for (multiplicand = 1; multiplicand < LIMIT; multiplicand++) {
            // Write into the buffer instead of calling printf in each iteration
            ptr += sprintf(ptr, "%dx%d=%d\n", multiplier, multiplicand, multiplier * multiplicand);
        }
    }

    // Print the entire buffer at once
    printf("%s", buffer);

    return 0;
}
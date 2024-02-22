#include <stdio.h>

unsigned char recent[99];
int index = 0, unique = 0, total = 0;

int main() {
    unsigned char buffer[4096], byte;
    size_t bytesRead, i;

    while ((bytesRead = fread(buffer, 1, sizeof buffer, stdin)) > 0) {
        for (i = 0; i < bytesRead; i++) {
            byte = buffer[i];

            // Clear the bit for the byte that was read 10 bytes ago
            if (index > 9) {
                recent[buffer[i - 10]] ^= 1 << ((i - 10) % 5);
            }

            // Update the counters
            total += !!recent[byte];
            unique += !(recent[byte] ^= 1 << (index % 5));

            // Print and reset the counters every 10 bytes
            if (++index > 9) {
                printf("%d %d\n", unique, total - unique);
                index = unique = total = 0;
            }
        }
    }

    return 0;
}
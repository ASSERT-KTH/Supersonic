#include <stdio.h>

#define MAX_NUM 10

int main(void) {
    int i, j;
    int results[MAX_NUM][MAX_NUM]; // 2D array to store multiplication results
    char buffer[50]; // Buffer to store string representation of each result

    // Calculate multiplication results
    for (i = 1; i < MAX_NUM; i++) {
        for (j = 1; j < MAX_NUM; j++) {
            results[i][j] = i * j;
        }
    }

    // Print multiplication results
    for (i = 1; i < MAX_NUM; i++) {
        for (j = 1; j < MAX_NUM; j++) {
            // Convert integer to string
            snprintf(buffer, sizeof(buffer), "%dx%d=%d\n", i, j, results[i][j]);
            // Print string
            fputs(buffer, stdout);
        }
    }

    return 0;
}
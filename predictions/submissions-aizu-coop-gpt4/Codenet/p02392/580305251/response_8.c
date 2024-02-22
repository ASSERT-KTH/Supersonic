#include <stdio.h>

#define BUFFER_SIZE 256

int main(void) {
    int a, b, c;
    char buffer[BUFFER_SIZE];

    if (fgets(buffer, BUFFER_SIZE, stdin) == NULL) {
        printf("Error reading input\n");
        return 1;
    }

    if (sscanf(buffer, "%d %d %d", &a, &b, &c) != 3) {
        printf("Invalid input. Please enter three integers\n");
        return 1;
    }

    if (a < b && b < c) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    return 0;
}
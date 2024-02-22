#include <stdio.h>
#include <stdlib.h>

#define s scanf("%d", &b)

int a, b, d;
int* c;

int main() {
    // Read the number of elements
    s;

    // Store the value of b in a separate variable
    int numElements = b;

    // Dynamically allocate memory for the array
    c = (int*)malloc(numElements * sizeof(int));

    // Initialize the array elements to zero
    for (int i = 0; i < numElements; i++) {
        c[i] = 0;
    }

    // Read the input numbers and update the array
    for (int i = 0; i < numElements; i++) {
        s;
        c[b]++;
    }

    // Calculate the sum of the input numbers using the updated array
    for (int i = 0; i < numElements; i++) {
        s;
        d += c[b];
    }

    printf("%d\n", d);

    // Free the dynamically allocated memory
    free(c);

    return 0;
}
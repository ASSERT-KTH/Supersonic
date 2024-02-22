#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, min = 2000000, max = 0, t;
    scanf("%d", &n);
    
    // Find the max element to dynamically allocate the array
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        if (t < min) min = t;
        if (t > max) max = t;
    }
    
    // Allocate memory for the array based on the max element
    int* A = (int*)calloc(max + 1, sizeof(int));
    
    // Re-read the input and store the count of each number
    rewind(stdin);
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &t);
        A[t]++;
    }
    
    // Print the numbers in ascending order
    printf("%d", min);
    A[min]--;
    for (int i = min; i <= max; i++) {
        for(int j = 0; j < A[i]; j++) {
            printf(" %d", i);
        }
    }
    printf("\n");
    
    // Free the dynamically allocated memory
    free(A);
    return 0;
}
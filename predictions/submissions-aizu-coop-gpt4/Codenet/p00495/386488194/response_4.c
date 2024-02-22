#include <stdio.h>
#include <stdlib.h>

// Function to find the maximum length of sequence
int findMaxLength(int* arr, int size, int num) {
    int* diff = malloc(size * sizeof(int));
    int maxLen = 0, temp = 0, currLen = 0;

    for (int i = 0; i < size; i++)
        diff[i] = 0;

    for (int i = 0; i < size; i++) {
        temp = diff[i];
        diff[i] = num != arr[i] ? currLen : temp + 1;
        currLen = num != arr[i] ? currLen : temp + 1;

        if (maxLen < currLen)
            maxLen = currLen;
    }

    free(diff);
    return maxLen;
}

int main() {
    int size;
    if(scanf("%d", &size) != 1) {
        fprintf(stderr, "Error reading input\n");
        return 1;
    }

    int* arr = malloc(size * sizeof(int));

    for (int i = 0; i < size; i++)
        if(scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Error reading input\n");
            return 1;
        }

    int num;
    while (scanf("%d", &num) == 1) {
        int maxLen = findMaxLength(arr, size, num);
        if(printf("%d\n", maxLen) < 0) {
            fprintf(stderr, "Error writing output\n");
            return 1;
        }
    }

    free(arr);
    return 0;
}
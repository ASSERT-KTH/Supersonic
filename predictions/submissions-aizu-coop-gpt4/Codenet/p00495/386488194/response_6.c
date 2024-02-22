#include<stdio.h>
#include<stdlib.h>

int main() {
    int size, i = 0, max = 0, temp = 0, input;
    int *sequence = NULL, *temp_sequence = NULL;
    scanf("%d", &size);
    
    /* Allocate memory for the sequence */
    sequence = (int*) malloc(size * sizeof(int));
    temp_sequence = (int*) malloc(size * sizeof(int));
    
    /* Read the sequence */
    for (; i < size; i++) {
        scanf("%d", &sequence[i]);
    }
    
    /* Perform the algorithm */
    for (i = 0; i < size; i++) {
        temp_sequence[i] = (sequence[i] <= max ? max = temp : temp) + 1;
        temp = temp_sequence[i];
    }
    
    /* Find the maximum value */
    for (i = 0; i < size; i++) {
        if (temp_sequence[i] > max) {
            max = temp_sequence[i];
        }
    }
    
    /* Print the maximum value */
    printf("%d\n", max);
    
    /* Free the memory */
    free(sequence);
    free(temp_sequence);
    
    return 0;
}
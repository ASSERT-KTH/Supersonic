#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, d = 0;
    
    // Read the number of inputs
    scanf("%d", &b);
    
    // Calculate the sum directly in the loop
    for (int i = 0; i < b; i++) {
        int input;
        scanf("%d", &input);
        d += input;
    }
    
    printf("%d\n", d);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    int b, d = 0;
    int* c = NULL;
    char input[1000];
    
    fgets(input, sizeof(input), stdin);
    b = atoi(input);
    
    c = (int*) calloc(b, sizeof(int));
    if (c == NULL) {
        printf("Memory allocation error.\n");
        return 1;
    }
    
    for (int i = 0; i < b; i++) {
        fgets(input, sizeof(input), stdin);
        c[atoi(input)] = 1;
    }
    
    fgets(input, sizeof(input), stdin);
    b = atoi(input);
    
    for (int i = 0; i < b; i++) {
        fgets(input, sizeof(input), stdin);
        d += c[atoi(input)];
    }
    
    printf("%d\n", d);
    
    free(c);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, numElements, printChar;
    char* t;

    while (scanf("%d", &numElements) && numElements) {
        t = (char*)malloc(numElements * sizeof(char));
        memset(t, 0, numElements * sizeof(char));

        for (n = 0; n < numElements; n++) {
            scanf(" %c %c", &printChar, &t[n]);
        }

        scanf("%d", &numElements);

        for (n = 0; n < numElements; n++) {
            putchar(!t[n] * n + t[n]);
        }

        free(t);
        printf("\n");
    }

    return 0;
}
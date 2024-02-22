#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, d = 0;
    int* c = NULL;
    int* unique = NULL;
    int uniqueSize = 0;

    char line[1024];
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &b);

    c = (int*)malloc(b * sizeof(int));
    unique = (int*)calloc(b, sizeof(int));

    for (a = 0; a < b; a++) {
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &c[a]);
    }

    for (a = 0; a < b; a++) {
        if (unique[c[a]] == 0) {
            unique[c[a]] = 1;
            d += c[a];
        }
    }

    printf("%d\n", d);

    free(c);
    free(unique);

    return 0;
}
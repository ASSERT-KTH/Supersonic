#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int *c = malloc((argc - 2) * sizeof(int));
    int x = atoi(argv[1]);
    int m = 0;
    
    for (int i = 0; i < argc - 2; i++) {
        c[i] = atoi(argv[i + 2]);
    }
    
    for (int i = 0; i < argc - 2; i++) {
        int u = 0;
        int t = 0;
        for (int j = 0; j < argc - 2; j++) {
            int d = (x - c[j]) ? u : t + 1;
            t = d;
            if (m < u) {
                m = u;
            }
            u = d;
        }
    }
    
    printf("%d\n", m);
    
    free(c);
    return 0;
}
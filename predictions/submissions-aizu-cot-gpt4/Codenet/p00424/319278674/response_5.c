#include <stdio.h>
#include <string.h> 

int main() {
    int n = 0, i = 0;
    char t[128]; // Assuming ASCII values

    while ((n = getchar()) != EOF) {
        memset(t, 0, sizeof(t));

        while (n--) {
            i = getchar();
            t[i] = getchar();
        }
        
        n = getchar();
        while (n--) {
            i = getchar();
            putchar(!t[i] ? i : t[i]);
        }
        putchar('\n');
    }
    return 0;
}
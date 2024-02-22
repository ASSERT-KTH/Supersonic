#include <stdio.h>
#include <string.h>

int main() {
    int n, t[999];
    int result;
    
    while ((result = scanf("%d", &n)) != EOF && n) {
        memset(t, 0, sizeof(t));
        
        while (n--) {
            int index;
            char value;
            scanf(" %d %c", &index, &value);
            t[index] = value;
        }
        
        scanf("%d", &n);
        
        while (n--) {
            int index;
            scanf(" %d", &index);
            char output = t[index];
            putchar(output);
        }
        
        putchar('\n');
    }

    return 0;
}
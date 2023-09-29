#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 999

int main() {
    int n;
    char t[MAX_SIZE];
    memset(t, '\0', sizeof(t)); // initialize t with null characters
    
    while (scanf("%d", &n) == 1) {
        for (int i = 0; i < n; i++) {
            char op;
            scanf(" %c", &op);
            
            if (op == 'c') {
                int index;
                char val;
                scanf(" %d %c", &index, &val);
                t[index - 1] = val;
            } else {
                int start, end;
                scanf(" %d %d", &start, &end);
                for (int j = start - 1; j < end; j++) {
                    putchar(!t[j] * j + t[j]);
                }
                putchar('\n');
            }
        }
        memset(t, '\0', sizeof(t)); // reset t for next testcase
    }
    return 0;
}
#include <stdio.h>

int main() {
    int a[4];
    char output[440001];
    
    while (1) {
        for (int i = 0; i < 4; ++i) {
            scanf("%d", &a[i]);
        }
        if (a[0] == 0) {
            break;
        }
        for (int i = 0; i < 110000; ++i) {
            output[i] = '(';
        }
        int length = sprintf(output + 110000, "%d+%d+%d+%d\n", a[0], a[1], a[2], a[3]);
        fwrite(output, sizeof(char), 110000 + length, stdout);
    }
}
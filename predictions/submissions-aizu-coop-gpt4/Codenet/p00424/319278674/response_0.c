#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    int *t = NULL;
    char line[999 * 3 + 1], ch, *p;
    char output[999 + 1], *q;

    while (scanf("%d", &n) == 1) {
        t = realloc(t, n * sizeof(int));
        memset(t, 0, n * sizeof(int));

        fgets(line, sizeof(line), stdin);
        for (p = line; n--; ) {
            sscanf(p, " %c", &ch);
            t[ch] = *(p + 2);
            p += 3;
        }

        scanf("%d", &n);
        fgets(line, sizeof(line), stdin);

        for (p = line, q = output; n--; ) {
            sscanf(p, " %c", &ch);
            *q++ = !t[ch] * ch + t[ch];
            p += 2;
        }

        fwrite(output, 1, q - output, stdout);
        putchar('\n');
    }

    free(t);
    return 0;
}
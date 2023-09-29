#include <stdio.h>
int main(void) {
    int Cards[4][14] = {{}};
    int i, j, n, Num;
    char Mark, c;
    scanf("%d", &n);
    while ((c = getchar()) != EOF && c != '\n');
    for (i = 0; i < 2 * n; i++) {
        scanf("%c%d", &Mark, &Num);
        getchar();
        Cards[Mark == 'S' ? 0 : Mark == 'H' ? 1 : Mark == 'C' ? 2 : 3][Num - 1] = 1;
    }
    for (j = 0; j < 4; ++j) {
        for (i = 0; i < 13; ++i) {
            if (!Cards[j][i]) {
                printf("%c %d\n", j == 0 ? 'S' : j == 1 ? 'H' : j == 2 ? 'C' : 'D', i + 1);
            }
        }
    }
    return 0;
}
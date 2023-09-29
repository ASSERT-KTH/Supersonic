#include <stdio.h>
int main(void) {
    int Cards[4][14] = {{}};
    int i, j, n, Num;
    char Mark, c;
    scanf("%d", &n);
    for (i = 0; i < 2 * n; i++) {
        scanf(" %c%d", &Mark, &Num);
        if (Mark == 'S') {
            Cards[0][Num - 1] = 1;
        } else if (Mark == 'H') {
            Cards[1][Num - 1] = 1;
        } else if (Mark == 'C') {
            Cards[2][Num - 1] = 1;
        } else {
            Cards[3][Num - 1] = 1;
        }
    }
    for (i = 0; i < 4; i++) {
        c = i == 0 ? 'S' : i == 1 ? 'H' : i == 2 ? 'C' : 'D';
        for (j = 0; j < 13; j++) {
            if (!Cards[i][j]) {
                printf("%c %d\n", c, j + 1);
            }
        }
    }
    return 0;
}
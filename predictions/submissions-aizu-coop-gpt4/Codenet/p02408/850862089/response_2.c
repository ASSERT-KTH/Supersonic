#include <stdio.h>

int main(void) {
    int Cards[4][14] = {{}};
    int i, j, n, Num;
    char Mark;
    char buffer[10];

    fgets(buffer, sizeof(buffer), stdin);
    sscanf(buffer, "%d", &n);

    for (i = 0; i < 2 * n; i++) {
        fgets(buffer, sizeof(buffer), stdin);
        sscanf(buffer, "%c %d", &Mark, &Num);

        switch(Mark) {
            case 'S':
                Cards[0][Num - 1] = 1;
                break;
            case 'H':
                Cards[1][Num - 1] = 1;
                break;
            case 'C':
                Cards[2][Num - 1] = 1;
                break;
            case 'D':
                Cards[3][Num - 1] = 1;
                break;
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 1; j < 14; j++) {
            if (Cards[i][j - 1] != 1) {
                printf("%c %d\n", "SHCD"[i], j);
            }
        }
    }

    return 0;
}
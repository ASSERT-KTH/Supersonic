#include<stdio.h>
int main(void) {
    int Cards[4][14] = {0};
    int i, j, n, Num;
    char Mark;
    scanf("%d", &n);
    getchar(); // read and discard the newline character left in the buffer
    for (i = 0; i < 2 * n; i++) {
        scanf("%c%d", &Mark, &Num);
        getchar(); // read and discard the newline character left in the buffer
        switch(Mark) {
            case 'S': Cards[0][Num - 1] = 1; break;
            case 'H': Cards[1][Num - 1] = 1; break;
            case 'C': Cards[2][Num - 1] = 1; break;
            case 'D': Cards[3][Num - 1] = 1; break;
        }
    }
    for (j = 0; j < 4; j++) {
        for (i = 0; i < 13; i++) {
            if (Cards[j][i] != 1) {
                printf("%c %d\n", j == 0 ? 'S' : j == 1 ? 'H' : j == 2 ? 'C' : 'D', i + 1);
            }
        }
    }
    return 0;
}
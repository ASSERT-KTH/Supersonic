#include <cstdio>

int main() {
    char Cards[4][14] = {{0}};
    int n, Num;
    char Mark;

    scanf("%d", &n);
    n *= 2;
    while (n--) {
        scanf(" %c %d", &Mark, &Num);
        Cards[Mark % 5][Num - 1] = 1;
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 13; ++j) {
            if (Cards[i][j] == 0) {
                printf("%c %d\n", "SHCD"[i], j + 1);
            }
        }
    }

    return 0;
}
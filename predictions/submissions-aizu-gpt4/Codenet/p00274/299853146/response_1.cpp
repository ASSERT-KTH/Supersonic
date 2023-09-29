#include <stdio.h>

int main(void) {
    int n, k, s = 0, i, flg = 0;
    while (scanf("%d", &n), n) {
        s = n;
        flg = 0;
        for (i = 0; i < n && scanf("%d", &k); i++) {
            s -= !k;
            flg |= k >= 2;
        }
        printf(flg ? "%d\n" : "NA\n", s + 1);
    }
    return 0;
}
#include <stdio.h>

int main() {
    int h, m, s;
    while (scanf("%d%d%d", &h, &m, &s) == 3) {
        int t = (120 - h * 60 - m) * 60 - s;
        for (int i = 0; i < 2; ++i, t *= 3) {
            printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
        }
    }
    return 0;
}
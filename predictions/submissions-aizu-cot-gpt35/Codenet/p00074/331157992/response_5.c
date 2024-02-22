#include <stdio.h>

int main() {
    int h, m, s;
    int t, temp;

    while (scanf("%d%d%d", &h, &m, &s) == 3) {
        t = (120 - h * 60 - m) * 60 - s;
        for (h = 2; h > 0; h--) {
            temp = t / 3600;
            printf("%02d:%02d:%02d\n", temp, (t / 60) % 60, t % 60);
            t *= 2;
        }
    }

    return 0;
}
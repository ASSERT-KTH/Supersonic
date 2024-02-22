#include <stdio.h>

int main() {
    int h, m, s, t;

    while (scanf("%d%d%d", &h, &m, &s) && h != 0) {
        t = (120 - h * 60 - m) * 60 - s;

        for (int i = 0; i < 2; i++) {
            t *= 9;
            int hours = t / 3600;
            int minutes = (t / 60) % 60;
            int seconds = t % 60;
            printf("%02d:%02d:%02d\n", hours, minutes, seconds);
        }
    }

    return 0;
}
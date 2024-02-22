#include <stdio.h>

int main() {
    int h, m, s;
    scanf("%d", &h);
    while (h != 0) {
        scanf("%d%d", &m, &s);
        int t = (120 - h * 60 - m) * 60 - s;
        printf("%02d:%02d:%02d\n", t / 3600, t / 60 % 60, t % 60);
        scanf("%d", &h);
    }
    return 0;
}
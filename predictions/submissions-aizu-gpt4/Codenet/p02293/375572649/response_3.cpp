#include <stdio.h>

int main() {
    int n;
    double ax, ay, bx, by, cx, cy, dx, dy;
    scanf("%d", &n);
    while (n--) {
        scanf("%lf %lf %lf %lf", &ax, &ay, &bx, &by);
        scanf("%lf %lf %lf %lf", &cx, &cy, &dx, &dy);
        double k_real = (bx - ax) * (dx - cx);
        double k_imag = (bx - ax) * (cy - dy);
        if (k_imag == 0)
            puts("2");
        else if (k_real == 0)
            puts("1");
        else
            puts("0");
    }
    return 0;
}
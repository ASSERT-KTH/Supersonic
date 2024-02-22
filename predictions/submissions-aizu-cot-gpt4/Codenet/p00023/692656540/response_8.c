#include <math.h>
#include <stdio.h>
int main(void) {
    int k, n;
    double xa, ya, ra, xb, yb, rb;
    scanf("%d", &n);
    for (k = 1; k <= n; k++) {
        scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);
        double d0 = sqrt((xb - xa)*(xb - xa) + (yb - ya)*(yb - ya));
        double d1 = ra + rb;
        double d2 = fabs(ra - rb); // absolute value of the difference
        int ans;
        if (d0 > d1) {
            ans = 0;
        } else if (d2 > d0) {
            ans = ra > rb ? 2 : -2;
        } else {
            ans = 1;
        }
        printf("%d\n", ans);
    }
    return 0;
}
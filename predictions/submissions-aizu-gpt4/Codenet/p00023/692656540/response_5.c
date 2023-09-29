#include <cstdio>
#include <cmath>

int main() {
    int n;
    scanf("%d", &n);
    
    double xa, ya, ra, xb, yb, rb, dist, sum, diff1, diff2;
    
    while(n--) {
        scanf("%lf %lf %lf %lf %lf %lf", &xa, &ya, &ra, &xb, &yb, &rb);

        dist = hypot(xb - xa, yb - ya); // calculate the distance using hypot function
        sum = ra + rb;
        diff1 = fabs(ra - rb); // calculate absolute difference between ra and rb

        if (dist > sum) {
            printf("0\n");
        } else if (diff1 > dist) {
            printf("%d\n", ra > rb ? 2 : -2);
        } else {
            printf("1\n");
        }
    }
    return 0;
}
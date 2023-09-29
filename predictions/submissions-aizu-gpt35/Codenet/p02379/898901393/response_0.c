#include <math.h>
#include <stdio.h>
typedef struct point {
    double x;
    double y;
} point;

double distance(const point& p1, const point& p2) {
    double temp = pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2);
    return sqrt(temp);
}

int main() {
    point p1, p2;
    scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
    printf("%.5f\n", distance(p1, p2));
    return 0;
}
#include <stdio.h>

typedef struct {
    double x;
    double y;
} point;

double distance(point p1, point p2) {
    return (p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y);
}

int main(void) {
    point p1, p2;
    double d;
    scanf("%lf%lf%lf%lf", &p1.x, &p1.y, &p2.x, &p2.y);
    d = distance(p1, p2);
    printf("%.5f\n", d);
    return 0;
}
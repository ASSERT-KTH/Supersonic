#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct point {
    double x;
    double y;
} point;

double distance(point *p1, point *p2) {
    double temp;
    temp = (p1->x - p2->x) * (p1->x - p2->x) + (p1->y - p2->y) * (p1->y - p2->y);
    return sqrt(temp);
}

int main(void) {
    point *p1 = (point *) malloc(sizeof(point));
    point *p2 = (point *) malloc(sizeof(point));
    double d;

    scanf("%lf%lf%lf%lf", &p1->x, &p1->y, &p2->x, &p2->y);
    d = distance(p1, p2);
    printf("%.5f\n", d);

    free(p1);
    free(p2);
    return 0;
}
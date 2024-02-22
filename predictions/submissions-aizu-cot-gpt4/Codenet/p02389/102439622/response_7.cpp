#include <stdio.h>

int main() {
    int area, c;
    scanf("%d %d", &area, &c);
    area *= c;
    c = 2 * (area/c + c);
    printf("%d %d\n", area, c);
    return 0;
}
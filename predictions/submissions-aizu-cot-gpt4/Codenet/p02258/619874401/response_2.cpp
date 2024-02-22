#include <stdio.h>
static const int MAX = 200000;
int R[MAX];
int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &R[i]);
    int maxv = R[1] - R[0];
    int minv = R[0];
    for (int i = 1; i < n; i++) {
        int tmp = R[i] - minv;
        if (tmp > maxv) maxv = tmp;
        if (R[i] < minv) minv = R[i];
    }
    printf("%d\n", maxv);
    return 0;
}
#include <stdio.h>

int main() {
    int numbers[5004];
    int count;

    scanf("%d%*d", &count);
    for (int i = 0; i < count; i++) {
        scanf("%d", &numbers[i]);
    }

    int x;
    int m = 0;
    while (scanf("%d", &x) != EOF) {
        int u = 0;
        for (int i = 0; i < count; i++) {
            int t = u;
            u = x - numbers[i] ? u : t + 1;
            m = m < u ? u : m;
        }
    }

    printf("%d\n", m);
    return 0;
}
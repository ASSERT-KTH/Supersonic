#include <cstdio>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    while (scanf("%d %d", &n, &k) != EOF) {
        if (n / 2 < k) {
            printf("-1\n");
            continue;
        }
        int p[n + 2];
        p[0] = 0;
        for (int i = 1; i < n; i += 2) {
            p[i] = i / 2 + 1;
            p[i + 1] = n - p[i];
        }
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < n - 1; j++) {
                int a = (p[j] + i) % n + 1;
                int b = (p[j + 1] + i) % n + 1;
                if (j != 0) printf(" ");
                printf("%d %d", a, b);
            }
            printf("\n");
        }
    }
}
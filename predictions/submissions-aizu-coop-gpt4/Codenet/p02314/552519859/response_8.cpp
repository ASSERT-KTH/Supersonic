#include <iostream>
#include <vector>
#include <algorithm>

const int maxN = 50001;
const int maxM = 21;
int mini[maxN];
int c[maxM];

int main() {
    std::ios_base::sync_with_stdio(false);
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        scanf("%d", &c[i]);
    }
    std::sort(c+1, c+1+m);
    for (int i = 1; i <= m; i++) {
        for (int j = c[i]; j <= n; j++) {
            mini[j] = std::min(mini[j], mini[j - c[i]] + 1);
        }
    }
    printf("%d\n", mini[n]);
    return 0;
}
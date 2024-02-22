#include <cstdio>
#include <algorithm>
using namespace std;
const int INF = 2000000000;

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int c[21];
    int mini[50001] = {0};
    fill(mini + 1, mini + n + 1, INF);

    for (int i = 1; i <= m; i++) {
        scanf("%d", &c[i]);
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j <= n - c[i]; j++) {
            mini[j + c[i]] = min(mini[j] + 1, mini[j + c[i]]);
        }
    }
    printf("%d\n", mini[n]);
    return 0;
}
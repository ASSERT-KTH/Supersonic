#include <iostream>
#include <cstring>
using namespace std;

#define r(i, n) for (int i = 0; i < n; i++)
#define INF 100000000

int dp[512256];

int main() {
    int n, m;
    while (scanf("%d %d", &n, &m), n) {
        int b[m];
        int a[n + 1];
        r(i, m) scanf("%d", &b[i]);
        r(i, n) scanf("%d", &a[i + 1]);
        
        memset(dp, INF, sizeof(dp));
        dp[128] = 1;
        
        r(i, n) {
            r(k, m) {
                r(j, 256) {
                    if (dp[j] != INF) {
                        int p = j + b[k];
                        if (p > 255)
                            p = 255;
                        if (p < 0)
                            p = 0;
                        dp[p] = min(dp[p], dp[j] + (a[i + 1] - p) * (a[i + 1] - p));
                    }
                }
            }
        }
        
        int p = INF;
        r(i, 256) {
            if (dp[i] != INF) {
                p = min(p, dp[i]);
            }
        }
        
        printf("%d\n", p - 1);
    }
    return 0;
}
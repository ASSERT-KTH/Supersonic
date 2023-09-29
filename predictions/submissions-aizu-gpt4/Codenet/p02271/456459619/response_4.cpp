#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    int n, t;
    scanf("%d", &n);
    vector<int> N(n);
    for (int& num : N) {
        scanf("%d", &num);
    }
    scanf("%d", &t);
    while (t--) {
        int p;
        scanf("%d", &p);
        vector<bool> dp(p + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; ++i) {
            for (int j = p; j >= N[i]; --j) {
                dp[j] = dp[j] || dp[j - N[i]];
            }
        }
        puts(dp[p] ? "yes" : "no");
    }
    return 0;
}
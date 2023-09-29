#include <iostream>
#include <vector>
#include <cstdio>
#include <cstdlib>
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
        for (const int& num : N) {
            for (int i = p; i >= num; --i) {
                dp[i] = dp[i] || dp[i - num];
            }
        }
        puts(dp[p] ? "yes" : "no");
    }
    return 0;
}
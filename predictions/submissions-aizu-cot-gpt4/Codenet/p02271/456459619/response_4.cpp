#include <cstdio>
#include <vector>
using namespace std;

vector<int> N;
int n;
vector<vector<int>> dp;

bool solve(int i, int m) {
    if (m == 0) return true;
    if (i == n || m < 0) return false;
    if (dp[i][m] != -1) return dp[i][m];
    return dp[i][m] = solve(i + 1, m - N[i]) || solve(i + 1, m);
}

int main() {
    int t;
    scanf("%d", &n);
    N.resize(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &N[i]);
    }
    scanf("%d", &t);
    dp.resize(n, vector<int>(100005, -1));
    for (int i = 0; i < t; i++) {
        int p;
        scanf("%d", &p);
        if (solve(0, p)) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
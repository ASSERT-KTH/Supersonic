#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> N;
vector<vector<int>> dp;
int n;

bool solve(int i, int m) {
    if (m == 0) return true;
    if (i >= n || m < 0) return false;
    if (dp[i][m] != -1) return dp[i][m];
    return dp[i][m] = solve(i + 1, m - N[i]) || solve(i + 1, m);
}

int main() {
    int t;
    cin >> n;
    N.resize(n);
    for (int &i : N) cin >> i;
    cin >> t;

    while (t--) {
        int p;
        cin >> p;
        dp.assign(n, vector<int>(p+1, -1));
        cout << (solve(0, p) ? "yes" : "no") << "\n";
    }
    return 0;
}
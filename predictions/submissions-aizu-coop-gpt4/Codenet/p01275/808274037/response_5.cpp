#include <iostream>
#include <vector>
using namespace std;

const int M = 10;
int k, ans;
vector<int> dif(12);
vector<vector<int>> dp(12, vector<int>(12, -1));

void rec(int d, int p) {
    if (p == k) {
        ans = min(ans, d);
        return;
    }
    if (d >= ans || dp[d][p] != -1) {
        return;
    }
    dp[d][p] = d;
    int rot = dif[p];
    if (rot != 0) {
        rec(d + 1, p + 1);
    }
    rec(d, p + 1);
}

int main() {
    while (cin >> k, k) {
        string s, t;
        cin >> s >> t;
        for (int i = 0; i < k; i++) {
            dif[i] = ((int)(t[i] - s[i]) + M) % M;
        }
        ans = k;
        dp.assign(12, vector<int>(12, -1));
        rec(0, 0);
        cout << ans << endl;
    }
}
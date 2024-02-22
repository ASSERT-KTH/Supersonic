#include <iostream>
#include <vector>
using namespace std;

int k, ans;
vector<int> dif(12);
vector<vector<int>> dp(12, vector<int>(1000, -1));
const int M = 10;

int rec(int d, int p) {
  if (p == k) {
    return d;
  }

  if (dp[p][d] != -1) {
    return dp[p][d];
  }

  int ret = rec(d, p + 1);
  int rot = dif[p];

  if (rot != 0) {
    for (int i = p; i < k; i++) {
      dif[i] = (dif[i] - rot + M) % M;
    }

    ret = min(ret, rec(d + 1, p + 1));

    for (int i = p; i < k; i++) {
      dif[i] = (dif[i] + rot) % M;
    }
  }

  dp[p][d] = ret;
  return ret;
}

int main() {
  while (cin >> k, k) {
    string s, t;
    cin >> s >> t;

    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }

    ans = rec(0, 0);
    cout << ans << endl;

    for (auto &row : dp) {
      fill(row.begin(), row.end(), -1);
    }
  }
}
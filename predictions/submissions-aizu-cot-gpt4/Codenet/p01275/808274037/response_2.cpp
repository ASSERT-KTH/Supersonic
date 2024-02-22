#include <iostream>
#include <vector>
using namespace std;
vector<int> dp(12);
int dif[12];
const int M = 10;
int rec(int d, int p) {
  if (p == dp.size())
    return d;
  if (dp[p] != -1)
    return dp[p];
  int res = d;
  int rot = dif[p];
  if (rot != 0) {
    res = min(res, rec(d + 1, p + 1));
    for (int i = p; i < dp.size(); i++) {
      dif[i] = (dif[i] - rot + M) % M;
      res = min(res, rec(d + 1, p + 1));
    }
    for (int i = p; i < dp.size(); i++)
      dif[i] = (dif[i] + rot + M) % M;
  }
  dp[p] = res;
  return dp[p];
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int k;
  while (cin >> k, k) {
    fill(dp.begin(), dp.end(), -1);
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < k; i++) {
      dif[i] = ((int)(t[i] - s[i]) + M) % M;
    }
    cout << rec(0, 0) << '\n';
  }
}
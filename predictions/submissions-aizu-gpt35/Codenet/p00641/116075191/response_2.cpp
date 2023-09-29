#include <iostream>
using namespace std;
const int MAXN = 100100, MOD = 10007;
int n, b[2][MAXN], f[2][MAXN], ans;
bool v[MAXN];
int dfs(int s, int now, int maxi, int num) {
  v[now] = true;
  for (int i = 0; i < 2; i++) {
    if (!v[b[i][now]]) {
      if (maxi == f[i][now])
        num++;
      else if (maxi < f[i][now]) {
        maxi = f[i][now];
        num = 1;
      }
      if (b[i][now] == s)
        return num;
      return dfs(s, b[i][now], maxi, num);
    }
  }
  if (maxi == f[1][s])
    return num + 1;
  else if (maxi < f[1][s])
    return 1;
  else
    return num;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> n, n) {
    ans = 1;
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
    }
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % MOD;
      }
    }
    cout << ans << "\n";
  }
  return 0;
}
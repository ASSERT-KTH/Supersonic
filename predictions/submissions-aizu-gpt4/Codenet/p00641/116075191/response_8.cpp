#include <iostream>
using namespace std;
constexpr int MAXN = 100100;
int n, b[2][MAXN], f[2][MAXN];
bool v[MAXN];
int dfs(int s, int now, int maxi, int num) {
  v[now] = true;
  int next_val;
  for (int i = 0; i < 2; ++i) {
    if (!v[next_val = b[i][now]]) {
      if (maxi == f[i][now])
        ++num;
      else if (maxi < f[i][now]) {
        maxi = f[i][now];
        num = 1;
      }
      if (next_val == s)
        return num;
      return dfs(s, next_val, maxi, num);
    }
  }
  return (maxi < f[1][s]) ? 1 : num + (maxi == f[1][s]);
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> n, n) {
    for (int i = 0; i < n; ++i) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
    }
    int ans = 1;
    for (int i = 0; i < n; ++i) {
      if (!v[i]) {
        v[i] = true;
        ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % 10007;
      }
    }
    cout << ans << '\n';
  }
}
#include <iostream>
using namespace std;
const int MAXN = 100100;
int n, b[2][MAXN], f[2][MAXN];
bool v[MAXN];
int dfs(int s, int now, int maxi, int num) {
  v[now] = true;
  int tmp_num = 0, tmp_maxi = maxi;
  for (int i = 0; i < 2; i++) {
    if (!v[b[i][now]]) {
      if (maxi == f[i][now])
        tmp_num += num;
      else if (maxi < f[i][now]) {
        tmp_maxi = f[i][now];
        tmp_num = num;
      }
      tmp_num %= 10007;
      int res = dfs(s, b[i][now], tmp_maxi, tmp_num);
      return res;
    }
  }
  if (maxi == f[1][s])
    return (num + 1) % 10007;
  else if (maxi < f[1][s])
    return 1;
  else
    return num % 10007;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % 10007;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
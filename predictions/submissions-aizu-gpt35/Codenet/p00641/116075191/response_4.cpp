#include <iostream>
using namespace std;
const int MAXN = 100100;
int n, b[2][MAXN], f[2][MAXN], ans = 1;
bool v[MAXN];
int dfs(int s, int now, int maxi, int num) {
  v[now] = true;
  int ret = num;
  for (int i = 0; i < 2; i++) {
    if (!v[b[i][now]]) {
      if (maxi == f[i][now])
        ret = dfs(s, b[i][now], maxi, num + 1);
      else if (maxi < f[i][now])
        ret = dfs(s, b[i][now], f[i][now], 1);
      if (b[i][now] == s)
        ans = (ans * ret) % 10007;
    }
  }
  return ret;
}
int main() {
  while (cin >> n && n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
    }
    ans = 1;
    for (int i = 0; i < n; i++)
      if (!v[i])
        dfs(i, b[0][i], f[0][i], 1);
    cout << ans << endl;
  }
  return 0;
}
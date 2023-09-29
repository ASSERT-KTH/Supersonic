#include <iostream>
#include <vector>
using namespace std;

const int mod = 10007;
vector<int> b[2], f[2], v;
int n;

int dfs(int s, int now, int maxi, int num) {
  v[now] = 1;
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
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  while (cin >> n, n) {
    b[0].resize(n); f[0].resize(n); b[1].resize(n); f[1].resize(n); v.resize(n, 0);
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = 1;
        ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % mod;
      }
    }
    cout << ans << '\n';
  }
  return 0;
}
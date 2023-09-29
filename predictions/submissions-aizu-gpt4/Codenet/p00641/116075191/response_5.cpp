#include <iostream>
using namespace std;
int n, b[2][100100], f[2][100100];
bool v[100100];

int dfs(int s, int now, int& maxi, int& num) {
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
    num++;
  else if (maxi < f[1][s])
    num = 1;
  return num;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        int maxi = f[0][i], num = 1;
        ans = (ans * dfs(i, b[0][i], maxi, num)) % 10007;
      }
    }
    cout << ans << '\n';
  }
}
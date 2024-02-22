#include <iostream>
using namespace std;

int n, b[2][100100], f[2][100100];
bool v[100100];

int dfs(int s, int now, int maxi, int num) {
  v[now] = true;

  if (!v[b[0][now]]) {
    if (maxi == f[0][now])
      num++;
    else if (maxi < f[0][now]) {
      maxi = f[0][now];
      num = 1;
    }
    if (b[0][now] == s)
      return num;
    return dfs(s, b[0][now], maxi, num);
  }

  if (!v[b[1][now]]) {
    if (maxi == f[1][now])
      num++;
    else if (maxi < f[1][now]) {
      maxi = f[1][now];
      num = 1;
    }
    if (b[1][now] == s)
      return num;
    return dfs(s, b[1][now], maxi, num);
  }

  if (maxi == f[1][s])
    return num + 1;
  else if (maxi < f[1][s])
    return 1;
  else
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
        ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % 10007;
      }
    }

    cout << ans << endl;
  }

  return 0;
}
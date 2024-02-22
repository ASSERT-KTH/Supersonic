#include <iostream>
using namespace std;

const int MAXN = 100100;
int n, b[2][MAXN], f[2][MAXN];
bool v[MAXN];
int memo[MAXN];

int dfs(int s, int now, int maxi, int num) {
  v[now] = true;
  if (memo[now] != -1) {
    return memo[now];
  }
  for (int i = 0; i < 2; i++) {
    if (!v[b[i][now]]) {
      if (maxi == f[i][now])
        num++;
      else if (maxi < f[i][now]) {
        maxi = f[i][now];
        num = 1;
      }
      if (b[i][now] == s)
        return memo[now] = num;
      return memo[now] = dfs(s, b[i][now], maxi, num);
    }
  }
  if (maxi == f[1][s])
    return memo[now] = num + 1;
  else if (maxi < f[1][s])
    return memo[now] = 1;
  else
    return memo[now] = num;
}

int main() {
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
      memo[i] = -1; // initialize memo array
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
}
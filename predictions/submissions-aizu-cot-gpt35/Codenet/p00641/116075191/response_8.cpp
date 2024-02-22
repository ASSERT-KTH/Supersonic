#include <iostream>
using namespace std;

const int MAXN = 100100;
const int MOD = 10007;

int n, b[2][MAXN], f[2][MAXN];
bool v[MAXN];

int dfs(int s, int now, int maxi, int num) {
  v[now] = true;
  int newMaxi = maxi;
  int newNum = num;
  for (int i = 0; i < 1; i++) { // Iterate only once
    if (!v[b[i][now]]) {
      if (maxi == f[i][now])
        newNum++;
      else if (maxi < f[i][now]) {
        newMaxi = f[i][now];
        newNum = 1;
      }
      int result = dfs(s, b[i][now], newMaxi, newNum); // Recursively call dfs
      if (b[i][now] == s)
        return result;
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
  while (cin >> n, n) {
    for (int i = 0; i < n; i++) {
      cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
      v[i] = false;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % MOD;
      }
    }
    cout << ans << endl;
  }
}
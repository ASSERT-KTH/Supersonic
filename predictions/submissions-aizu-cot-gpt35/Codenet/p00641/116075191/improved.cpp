#include <cstdio>
using namespace std;
int n, b[2][100100], f[2][100100], maxi, num;
bool v[100100];
int dfs(int s, int now) {
  v[now] = true;
  for (int i = 0; i < 2; i++) {
    if (!v[b[i][now]]) {
      if (maxi == f[i][now])
        num++;
      else if (maxi < f[i][now]) {
        maxi = f[i][now];
        num = 1;
      }
      return dfs(s, b[i][now]);
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
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++) {
      scanf("%d%d%d%d", &b[0][i], &f[0][i], &b[1][i], &f[1][i]);
      v[i] = false;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        maxi = f[0][i];
        num = 1;
        ans = (ans * dfs(i, b[0][i])) % 10007;
      }
    }
    printf("%d\n", ans);
  }
}

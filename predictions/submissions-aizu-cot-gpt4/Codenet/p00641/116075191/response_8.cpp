#include <cstdio>
#define MAX 100100

int n, b[2][MAX], f[2][MAX];
bool v[MAX];

int dfs(int s, int now, int maxi, int num) {
  v[now] = true;
  for (int i = 0; i < 2; i++) {
    int b_now = b[i][now];
    int f_now = f[i][now];
    if (!v[b_now]) {
      if (maxi == f_now)
        num++;
      else if (maxi < f_now) {
        maxi = f_now;
        num = 1;
      }
      if (b_now == s)
        return num;
      return dfs(s, b_now, maxi, num);
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
  std::ios::sync_with_stdio(false);
  while (scanf("%d", &n), n) {
    for (int i = 0; i < n; i++) {
      scanf("%d %d %d %d", &b[0][i], &f[0][i], &b[1][i], &f[1][i]);
      v[i] = false;
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        ans = (ans * dfs(i, b[0][i], f[0][i], 1)) % 10007;
      }
    }
    printf("%d\n", ans);
  }
  return 0;
}
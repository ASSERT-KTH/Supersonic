#include <iostream>
#include <vector>
#include <array>

void dfs(int s, int now, int maxi, int& num, std::vector<bool>& v, const std::vector<std::array<int, 100100>>& b, const std::vector<std::array<int, 100100>>& f) {
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
        return;
      dfs(s, b[i][now], maxi, num, v, b, f);
      return;
    }
  }
  if (maxi == f[1][s])
    num++;
  else if (maxi < f[1][s])
    num = 1;
}

int main() {
  int n;
  while (std::scanf("%d", &n) == 1 && n != 0) {
    std::vector<std::array<int, 100100>> b(2);
    std::vector<std::array<int, 100100>> f(2);
    std::vector<bool> v(100100, false);

    for (int i = 0; i < n; i++) {
      std::scanf("%d %d %d %d", &b[0][i], &f[0][i], &b[1][i], &f[1][i]);
      v[i] = false;
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!v[i]) {
        v[i] = true;
        int num = 1;
        dfs(i, b[0][i], f[0][i], num, v, b, f);
        ans = (ans * num) % 10007;
      }
    }
    std::printf("%d\n", ans);
  }
  return 0;
}
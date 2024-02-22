#include <iostream>
#include <vector>

std::pair<int, int> dfs(int s, int now, const std::vector<std::vector<int>>& b, const std::vector<std::vector<int>>& f, std::vector<bool>& visited) {
  visited[now] = true;
  int maxi = 0, num = 0;
  for (int i = 0; i < 2; i++) {
    if (!visited[b[i][now]]) {
      if (maxi == f[i][now])
        num++;
      else if (maxi < f[i][now]) {
        maxi = f[i][now];
        num = 1;
      }
      if (b[i][now] == s)
        return {num, maxi};
      std::pair<int, int> result = dfs(s, b[i][now], b, f, visited);
      num += result.first;
      maxi = std::max(maxi, result.second);
    }
  }
  return {num, maxi};
}

int main() {
  int n;
  while (std::cin >> n && n != 0) {
    std::vector<std::vector<int>> b(2, std::vector<int>(n));
    std::vector<std::vector<int>> f(2, std::vector<int>(n));
    std::vector<bool> visited(n, false);

    for (int i = 0; i < n; i++) {
      std::cin >> b[0][i] >> f[0][i] >> b[1][i] >> f[1][i];
    }

    int ans = 1;
    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        visited[i] = true;
        std::pair<int, int> result = dfs(i, b[0][i], b, f, visited);
        ans = (ans * (result.first + 1)) % 10007;
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}
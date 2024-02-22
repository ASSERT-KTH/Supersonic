#include <iostream>
#include <vector>
#include <queue>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m, q;
  std::cin >> n >> m >> q;

  std::vector<std::vector<std::pair<int, int>>> x(n + 1), y(n + 1);
  std::vector<int> dist(n + 1, 999999), T(n + 1), U(n + 1);
  std::vector<bool> used(m);

  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    x[a].emplace_back(b, i);
    x[b].emplace_back(a, i);
  }

  dist[1] = 0;
  std::queue<int> Q;
  Q.push(1);

  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop();

    for (auto& i : x[a1]) {
      if (dist[i.first] > dist[a1] + 1) {
        dist[i.first] = dist[a1] + 1;
        Q.push(i.first);
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    for (auto& j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].emplace_back(j);
        T[j.first]++;
      }
    }
  }

  int cnt = 0;
  for (int i = 0; i < q; i++) {
    int c;
    std::cin >> c;
    c--;

    std::queue<std::pair<int, int>> Q1;

    if (dist[a[c]] < dist[b[c]] && U[b[c]] == 0 && !used[c]) {
      Q1.emplace(a[c], c);

      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop();

        if (U[a1] == 1 || used[a2])
          continue;

        T[a1]--;
        used[a2] = true;

        if (T[a1] != 0)
          continue;

        cnt++;
        U[a1] = 1;

        for (auto& j : y[a1]) {
          if (U[j.first] == 0)
            Q1.emplace(j);
        }
      }
    }

    std::cout << cnt << "\n";
  }

  return 0;
}
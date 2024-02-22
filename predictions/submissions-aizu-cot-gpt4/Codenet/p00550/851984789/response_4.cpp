#include <cstdio>
#include <deque>
#include <array>

const int MAX = 210000;
int n, m, q, a[MAX], b[MAX], c, dist[MAX], T[MAX], cnt, U[MAX];
std::array<std::deque<std::pair<int, int>>, MAX> x, y;
bool used[MAX];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    x[a[i]].push_back({b[i], i});
    x[b[i]].push_back({a[i], i});
  }
  std::fill(dist, dist + n + 1, 999999);
  dist[1] = 0;
  std::deque<int> Q;
  Q.push_back(1);
  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop_front();
    for (auto [first, _] : x[a1]) {
      if (dist[first] > dist[a1] + 1) {
        dist[first] = dist[a1] + 1;
        Q.push_back(first);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].push_back(j);
        T[j.first]++;
      }
    }
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", &c);
    c--;
    std::deque<std::pair<int, int>> Q1;
    int ss = dist[a[c]] > dist[b[c]] ? a[c] : b[c];
    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      Q1.push_back({ss, c});
      while (!Q1.empty()) {
        auto [a1, a2] = Q1.front();
        Q1.pop_front();
        if (U[a1] == 1 || used[a2] == true)
          continue;
        T[a1]--;
        used[a2] = true;
        if (T[a1] != 0)
          continue;
        cnt++;
        U[a1] = 1;
        for (auto j : y[a1]) {
          if (U[j.first] == 0)
            Q1.push_back(j);
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
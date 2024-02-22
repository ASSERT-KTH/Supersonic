#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>

using pii = std::pair<int, int>;
constexpr int MAXN = 210000;

int n, m, q, a[MAXN], b[MAXN], c, dist[MAXN/2], T[MAXN/2], cnt, U[MAXN/2];
std::vector<pii> x[MAXN/2], y[MAXN/2];
bool used[MAXN];

int main() {
  std::scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    std::scanf("%d%d", &a[i], &b[i]);
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
    for (pii i : x[a1]) {
      if (dist[i.first] > dist[a1] + 1) {
        dist[i.first] = dist[a1] + 1;
        Q.push_back(i.first);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (pii j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].push_back(j);
        T[j.first]++;
      }
    }
  }
  for (int i = 0; i < q; i++) {
    std::scanf("%d", &c);
    c--;
    std::deque<pii> Q1;
    int ss = -1;
    if (dist[a[c]] < dist[b[c]])
      ss = b[c];
    if (dist[a[c]] > dist[b[c]])
      ss = a[c];
    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      Q1.push_back({ss, c});
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop_front();
        if (U[a1] == 1 || used[a2] == true)
          continue;
        T[a1]--;
        used[a2] = true;
        if (T[a1] != 0)
          continue;
        cnt++;
        U[a1] = 1;
        for (pii j : y[a1]) {
          if (U[j.first] == 0)
            Q1.push_back(j);
        }
      }
    }
    std::printf("%d\n", cnt);
  }
  return 0;
}
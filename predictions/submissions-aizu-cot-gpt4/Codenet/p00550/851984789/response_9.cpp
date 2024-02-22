#include <cstdio>
#include <vector>
#include <queue>
#include <utility>

int n, m, q, a[210000], b[210000], c, dist[110000], T[110000], cnt, U[110000];
std::vector<std::pair<int, int>> x[110000], y[110000];
bool used[210000];

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  std::cout.tie(NULL);
  
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    x[a[i]].emplace_back(b[i], i);
    x[b[i]].emplace_back(a[i], i);
  }
  
  for (int i = 0; i <= n; ++i) dist[i] = 999999;
  dist[1] = 0;
  
  std::queue<int> Q;
  Q.push(1);
  
  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop();
    
    for (std::pair<int, int>& i : x[a1]) {
      if (dist[i.first] > dist[a1] + 1) {
        dist[i.first] = dist[a1] + 1;
        Q.push(i.first);
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    for (std::pair<int, int>& j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].emplace_back(j);
        ++T[j.first];
      }
    }
  }
  
  for (int i = 0; i < q; ++i) {
    scanf("%d", &c);
    --c;
    std::queue<std::pair<int, int>> Q1;
    int ss = -1;
    if (dist[a[c]] < dist[b[c]])
      ss = b[c];
    if (dist[a[c]] > dist[b[c]])
      ss = a[c];
    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      Q1.emplace(ss, c);
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop();
        if (U[a1] == 1 || used[a2] == true)
          continue;
        --T[a1];
        used[a2] = true;
        if (T[a1] != 0)
          continue;
        ++cnt;
        U[a1] = 1;
        for (std::pair<int, int>& j : y[a1]) {
          if (U[j.first] == 0)
            Q1.push(j);
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
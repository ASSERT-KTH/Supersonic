#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
#define MAXN 110000
#define MAXM 210000
#define INF 999999
using namespace std;

int n, m, q, a[MAXM], b[MAXM], c, dist[MAXN], T[MAXN], cnt, U[MAXN];
vector<pair<int, int>> x[MAXN], y[MAXN];
bool used[MAXM];

int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    x[a[i]].emplace_back(b[i], i);
    x[b[i]].emplace_back(a[i], i);
  }
  fill(dist, dist + n + 1, INF);
  dist[1] = 0;
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int a1 = Q.front(); Q.pop();
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
        y[i].push_back(j);
        T[j.first]++;
      }
    }
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", &c); c--;
    queue<pair<int, int>> Q1;
    int ss = -1;
    if (dist[a[c]] < dist[b[c]]) ss = b[c];
    if (dist[a[c]] > dist[b[c]]) ss = a[c];
    if (ss >= 1 && !U[ss] && !used[c]) {
      Q1.emplace(ss, c);
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second; Q1.pop();
        if (U[a1] || used[a2]) continue;
        T[a1]--; used[a2] = true;
        if (T[a1]) continue;
        cnt++; U[a1] = 1;
        for (auto& j : y[a1]) {
          if (!U[j.first]) Q1.push(j);
        }
      }
    }
    printf("%d\n", cnt);
  }
  return 0;
}
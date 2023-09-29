#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
typedef pair<int, int> P;
vector<vector<P>> G(100000);

int main() {
  int v, e, r;
  scanf("%d %d %d", &v, &e, &r);
  G.resize(v);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    G[s].emplace_back(t, d);
  }
  vector<int> d(v, INF);
  d[r] = 0;
  priority_queue<P, vector<P>, greater<P>> q;
  q.emplace(0, r);
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
    for (const auto &edge : G[nv]) {
      if (d[nv] + edge.second < d[edge.first]) {
        d[edge.first] = d[nv] + edge.second;
        q.emplace(d[edge.first], edge.first);
      }
    }
  }
  for (const auto &dist : d) {
    if (dist == INF)
      printf("INF\n");
    else
      printf("%d\n", dist);
  }
  return 0;
}
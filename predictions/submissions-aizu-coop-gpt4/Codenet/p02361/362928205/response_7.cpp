#include <algorithm>
#include <cstdio>
#include <queue>
#include <array>
#include <vector>
using namespace std;
const int INF = 1000000000;

struct edge {
  int to, cost;
};

array<vector<edge>, 100000> G;
int v, e, r;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> q;

int main() {
  scanf("%d %d %d", &v, &e, &r);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    G[s].push_back(edge{t, d});
  }

  vector<int> d(v, INF);
  d[r] = 0;
  q.push(P(0, r));

  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;

    // Use range-based for loop and avoid repeated computations
    for (auto &e : G[nv]) {
      int next_vertex = e.to;
      int new_dist = d[nv] + e.cost;
      if (new_dist < d[next_vertex]) {
        d[next_vertex] = new_dist;
        q.push(P(new_dist, next_vertex));
      }
    }
  }

  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      printf("INF\n");
    else
      printf("%d\n", d[i]);
  }
  return 0;
}
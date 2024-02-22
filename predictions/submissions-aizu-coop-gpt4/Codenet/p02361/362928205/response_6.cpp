#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct edge {
  int to, cost;
};
vector<edge> G[100000];
int v, e, r;
typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> q;
int main() {
  scanf("%d %d %d", &v, &e, &r);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    // push edge information directly onto the vector
    G[s].push_back({t, d});
  }
  int d[v];
  fill(d, d + v, INF);
  d[r] = 0;
  q.push(P(0, r));
  while (!q.empty()) {
    int nv = q.top().second;
    q.pop();
    if (q.top().first > d[nv])
      continue;
    // calculate size once and store in a variable
    int size = G[nv].size();
    for (int i = 0; i < size; i++) {
      if (d[nv] + G[nv][i].cost < d[G[nv][i].to]) {
        d[G[nv][i].to] = d[nv] + G[nv][i].cost;
        q.push(P(d[G[nv][i].to], G[nv][i].to));
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
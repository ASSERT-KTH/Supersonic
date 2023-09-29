#include <cstdio>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct edge {
  int to, cost;
};
vector<edge> G[100000];
int v, e, r, d[100000];
int main() {
  scanf("%d %d %d", &v, &e, &r);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    G[s].push_back({t, d});
  }
  fill(d, d + v, INF);
  d[r] = 0;
  for (int i = 0; i < G[r].size(); i++) {
    d[G[r][i].to] = G[r][i].cost;
  }
  for (int i = 1; i < v; i++) {
    for (int j = 0; j < v; j++) {
      for (int k = 0; k < G[j].size(); k++) {
        edge e = G[j][k];
        if (d[j] != INF && d[e.to] > d[j] + e.cost) {
          d[e.to] = d[j] + e.cost;
        }
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

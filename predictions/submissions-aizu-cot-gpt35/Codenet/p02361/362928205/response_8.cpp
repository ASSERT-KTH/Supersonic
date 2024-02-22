#include <cstdio>
#include <queue>
#include <vector>

const int INF = 1000000000;

struct edge {
  int to, cost;
};

std::vector<edge> G[100000];

int v, e, r;
typedef std::pair<int, int> P;
std::vector<P> q;

int main() {
  std::scanf("%d %d %d", &v, &e, &r);
  
  for (int i = 0; i < e; i++) {
    int s, t, d;
    std::scanf("%d %d %d", &s, &t, &d);
    edge tmp;
    tmp.to = t;
    tmp.cost = d;
    G[s].push_back(tmp);
  }
  
  std::vector<int> d(v, INF);
  d[r] = 0;
  q.push_back(P(0, r));
  
  while (!q.empty()) {
    std::sort(q.begin(), q.end());
    P p = q.front();
    q.erase(q.begin());
    
    int nv = p.second;
    if (p.first > d[nv])
      continue;
      
    for (auto& edge : G[nv]) {
      if (d[nv] + edge.cost < d[edge.to]) {
        d[edge.to] = d[nv] + edge.cost;
        q.push_back(P(d[edge.to], edge.to));
      }
    }
  }
  
  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      std::printf("INF\n");
    else
      std::printf("%d\n", d[i]);
  }
  
  return 0;
}
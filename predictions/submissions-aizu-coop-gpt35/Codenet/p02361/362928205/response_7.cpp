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
  scanf("%d%d%d", &v, &e, &r);
  
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d%d%d", &s, &t, &d);
    G[s].emplace_back(t, d);
  }
  
  vector<int> dist(v, INF);
  dist[r] = 0;
  
  q.emplace(0, r);
  
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    
    int nv = p.second;
    
    if (p.first > dist[nv])
      continue;
    
    for (const edge& e : G[nv]) {
      if (dist[nv] + e.cost < dist[e.to]) {
        dist[e.to] = dist[nv] + e.cost;
        q.emplace(dist[e.to], e.to);
      }
    }
  }
  
  for (int i = 0; i < v; i++) {
    if (dist[i] == INF)
      puts("INF");
    else
      printf("%d\n", dist[i]);
  }
  
  return 0;
}
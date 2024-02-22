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
    G[s].push_back({t,d}); // push_back can take arguments for constructor
  }
  
  vector<int> d(v, INF); // change from C array to vector
  d[r] = 0;
  q.emplace(0, r); // use emplace instead of push
  
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
      
    for (const edge &e : G[nv]) { // use range-based for loop and reference to reduce lookups
      if (d[nv] + e.cost < d[e.to]) {
        d[e.to] = d[nv] + e.cost;
        q.emplace(d[e.to], e.to); // use emplace instead of push
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
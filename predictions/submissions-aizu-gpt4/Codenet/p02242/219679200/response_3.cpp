#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> P;

struct edge { int to, cost; };
vector<edge> G[500000];
int d[500000];
const int INF = 1e9 + 7;

void dijkstra(int s){
  priority_queue<P, vector<P>, greater<P>> que;
  fill(d, d + 500000, INF);
  d[s] = 0;
  que.push(P(0, s));

  while(!que.empty()){
    P p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    for(int i = 0; i < G[v].size(); i++){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(P(d[e.to], e.to));
      }
    }
  }
}

int main(){
  int n; scanf("%d", &n);
  for(int i = 0; i < n; i++){
    int u, k; scanf("%d%d", &u, &k);
    for(int j = 0; j < k; j++){
      int v, c; scanf("%d%d", &v, &c);
      G[u].push_back((edge){v, c});
    }
  }
  dijkstra(0);
  for(int i = 0; i < n; i++)
    printf("%d %d\n", i, d[i]);
  return 0;
}
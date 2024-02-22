#include <cstdio>
#include <queue>
using namespace std;

const int INF = 1000000000;
const int MAX_V = 100000;

struct edge {
  int to, cost;
};

typedef pair<int, int> P;
priority_queue<P, vector<P>, greater<P>> q;

int G[MAX_V][MAX_V];
int d[MAX_V];

int main() {
  int v, e, r;
  scanf("%d %d %d", &v, &e, &r);
  
  for (int i = 0; i < v; i++) {
    for (int j = 0; j < v; j++) {
      G[i][j] = INF;
    }
  }

  for (int i = 0; i < e; i++) {
    int s, t, cost;
    scanf("%d %d %d", &s, &t, &cost);
    G[s][t] = cost;
  }

  fill(d, d + v, INF);
  d[r] = 0;
  q.push(P(0, r));
  
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    int u = p.second;
    if (p.first > d[u]) continue;
    for (int i = 0; i < v; i++) {
      if (G[u][i] != INF && d[u] + G[u][i] < d[i]) {
        d[i] = d[u] + G[u][i];
        q.push(P(d[i], i));
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
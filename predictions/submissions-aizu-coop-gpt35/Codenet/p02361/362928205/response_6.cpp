#include <cstdio>
#include <queue>
using namespace std;

const unsigned int INF = 1000000000;
const int MAX_V = 100000;
const int MAX_E = 100000;

struct edge {
  int to, cost;
};

edge G[MAX_V][MAX_E];
unsigned int d[MAX_V];

typedef pair<unsigned int, int> P;
P q[MAX_V];
int qSize;

void dijkstra(int v, int e, int r) {
  for (int i = 0; i < v; i++) {
    d[i] = INF;
  }
  
  d[r] = 0;
  qSize = 0;
  
  q[qSize++] = make_pair(0, r);
  make_heap(q, q + qSize);

  while (qSize > 0) {
    P p = q[0];
    pop_heap(q, q + qSize);
    qSize--;

    int nv = p.second;
    if (p.first > d[nv]) {
      continue;
    }

    for (int i = 0; i < e; i++) {
      int to = G[nv][i].to;
      unsigned int cost = G[nv][i].cost;

      if (d[nv] + cost < d[to]) {
        d[to] = d[nv] + cost;
        q[qSize++] = make_pair(d[to], to);
        push_heap(q, q + qSize);
      }
    }
  }
}

int main() {
  int v, e, r;
  scanf("%d %d %d", &v, &e, &r);

  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);

    G[s][i].to = t;
    G[s][i].cost = d;
  }

  dijkstra(v, e, r);

  for (int i = 0; i < v; i++) {
    if (d[i] == INF) {
      printf("INF\n");
    } else {
      printf("%u\n", d[i]);
    }
  }

  return 0;
}
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

static const int INFTY = (1 << 21);

int n, **M;

void dijkstra() {
  int d[n], color[n];
  priority_queue<pair<int, int>> PQ;

  for (int i = 0; i < n; i++) {
    d[i] = INFTY;
    color[i] = 0;
  }

  d[0] = 0;
  PQ.push(make_pair(0, 0));

  while (!PQ.empty()) {
    pair<int, int> f = PQ.top(); PQ.pop();
    int u = f.second;
    color[u] = 1;
    if (d[u] < f.first*(-1)) continue;

    for (int v = 0; v < n; v++) {
      if (color[v] != 1 && M[u][v] != INFTY) {
        if (d[v] > d[u] + M[u][v]) {
          d[v] = d[u] + M[u][v];
          PQ.push(make_pair(d[v]*(-1), v));
        }
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  cin >> n;
  
  M = new int*[n];
  for(int i = 0; i < n; ++i)
    M[i] = new int[n];
    
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      M[i][j] = INFTY;
    }
  }
  
  int k, c, u, v;
  for (int i = 0; i < n; i++) {
    cin >> u >> k;
    for (int j = 0; j < k; j++) {
      cin >> v >> c;
      M[u][v] = c;
    }
  }
  dijkstra();
  
  for(int i = 0; i < n; ++i)
    delete [] M[i];
  delete [] M;
  
  return 0;
}
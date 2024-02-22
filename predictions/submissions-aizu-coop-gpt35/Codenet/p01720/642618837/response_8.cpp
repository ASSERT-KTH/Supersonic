#include <iostream>
#include <vector>
#define INF (1 << 23)
using namespace std;

int main() {
  int N, M, s, t, u, v;
  cin >> N >> M >> s >> t;
  s--;
  t--;

  vector<vector<int>> G(N, vector<int>(N, 0));
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    G[u - 1][v - 1] = 1;
    G[v - 1][u - 1] = 1;
  }

  vector<int> d1(N, INF);
  vector<int> d2(N, INF);
  d1[s] = 0;
  d2[t] = 0;

  vector<int> que;
  que.push_back(s);
  for (int i = 0; i < que.size(); i++) {
    int node = que[i];
    for (int j = 0; j < N; j++) {
      if (G[node][j] && d1[j] == INF) {
        d1[j] = d1[node] + 1;
        que.push_back(j);
      }
    }
  }

  que.clear();
  que.push_back(t);
  for (int i = 0; i < que.size(); i++) {
    int node = que[i];
    for (int j = 0; j < N; j++) {
      if (G[node][j] && d2[j] == INF) {
        d2[j] = d2[node] + 1;
        que.push_back(j);
      }
    }
  }

  int shortest = d1[t];
  int ret = 0;
  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      ret++;
    }
  }

  int count = 0;
  for (int i = 0; i < N; i++) {
    if (d2[i] < shortest - 1) {
      count++;
    }
  }
  ret *= count;

  cout << ret << endl;
  return 0;
}
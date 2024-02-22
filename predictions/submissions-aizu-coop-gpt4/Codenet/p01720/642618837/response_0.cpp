#include <iostream>
#include <queue>
#include <vector>
#define INF (1 << 23)
using namespace std;

int main() {
  int N, M, s, t, u, v;
  scanf("%d %d %d %d", &N, &M, &s, &t);
  s--; t--;
  vector<vector<int>> G(N), R(N);
  for (int i = 0; i < M; ++i) {
    scanf("%d %d", &u, &v);
    u--; v--;
    G[u].push_back(v);
    R[v].push_back(u);  // Reverse graph
  }
  vector<int> d(N, INF), r1(N, 0), r2(N, 0);
  d[s] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (int i = 0, sz = G[node].size(); i < sz; ++i) {
      int next_node = G[node][i];
      if (d[next_node] == INF) {
        d[next_node] = d[node] + 1;
        que.push(next_node);
      }
    }
  }
  int shortest = d[t];
  for (int i = 0; i < N; ++i) if (d[i] < shortest) ++r1[d[i]];
  fill(d.begin(), d.end(), INF);
  d[t] = 0;
  que.push(t);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (int i = 0, sz = R[node].size(); i < sz; ++i) {
      int next_node = R[node][i];
      if (d[next_node] == INF) {
        d[next_node] = d[node] + 1;
        que.push(next_node);
      }
    }
  }
  for (int i = 0; i < N; ++i) if (d[i] < shortest) ++r2[d[i]];
  long long ret = 0;
  for (int i = 0; i < shortest; ++i) ret += (long long)r1[i] * r2[shortest - i - 1];
  printf("%lld\n", ret);
  return 0;
}
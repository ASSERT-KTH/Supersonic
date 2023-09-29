#include <iostream>
#include <vector>
#include <queue>
#define INF (1 << 23)
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N, M, s, t, u, v;
  cin >> N >> M >> s >> t;
  s--; t--;
  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }
  vector<int> d1(N, INF), d2(N, INF);
  d1[s] = 0; d2[t] = 0;
  queue<int> que;
  que.push(s);
  while (!que.empty()) {
    int node = que.front(); que.pop();
    for (auto& next_node : G[node]) {
      if (d1[next_node] == INF) {
        d1[next_node] = d1[node] + 1;
        que.push(next_node);
      }
    }
  }
  que.push(t);
  while (!que.empty()) {
    int node = que.front(); que.pop();
    for (auto& next_node : G[node]) {
      if (d2[next_node] == INF) {
        d2[next_node] = d2[node] + 1;
        que.push(next_node);
      }
    }
  }
  int shortest = d1[t];
  vector<int> r1(shortest - 1, 0), r2(shortest - 1, 0);
  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1[d1[i]]++;
    }
    if (d2[i] < shortest - 1) {
      r2[d2[i]]++;
    }
  }
  long long ret = 0;
  for (int i = 0; i < shortest - 1; i++) {
    ret += 1LL * r1[i] * r2[shortest - i - 2];
  }
  cout << ret << "\n";
  return 0;
}
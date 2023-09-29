#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define INF (1 << 23)

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N, M, s, t, u, v;
  cin >> N >> M >> s >> t;
  --s, --t;
  vector<vector<int>> G(N);
  for (int i = 0; i < M; ++i) {
    cin >> u >> v;
    G[--u].push_back(--v);
    G[v].push_back(u);
  }
  vector<int> d1(N, INF), d2(N, INF);
  d1[s] = 0;
  d2[t] = 0;
  queue<int> que1, que2;
  que1.push(s);
  while (!que1.empty()) {
    int node = que1.front();
    que1.pop();
    for (int i = 0; i < G[node].size(); ++i) {
      if (d1[G[node][i]] == INF) {
        d1[G[node][i]] = d1[node] + 1;
        que1.push(G[node][i]);
      }
    }
  }
  que2.push(t);
  while (!que2.empty()) {
    int node = que2.front();
    que2.pop();
    for (int i = 0; i < G[node].size(); ++i) {
      if (d2[G[node][i]] == INF) {
        d2[G[node][i]] = d2[node] + 1;
        que2.push(G[node][i]);
      }
    }
  }
  int shortest = d1[t];
  vector<int> r1(shortest - 1), r2(shortest - 1);
  for (int i = 0; i < N; ++i) {
    if (d1[i] < shortest - 1) {
      ++r1[d1[i]];
    }
    if (d2[i] < shortest - 1) {
      ++r2[d2[i]];
    }
  }
  long long ret = 0;
  for (int i = 0; i < shortest - 1; ++i) {
    ret += (long long)r1[i] * r2[shortest - i - 2];
  }
  cout << ret << '\n';
  return 0;
}
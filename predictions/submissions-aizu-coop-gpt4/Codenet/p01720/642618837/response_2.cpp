#include <iostream>
#include <queue>
#include <vector>
#include <list>
#include <array>

#define INF (1 << 23)

using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int N, M, s, t, u, v;
  cin >> N >> M >> s >> t;
  s--; t--;

  vector<list<int>> G(N);
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }

  array<int, INF> d1;
  d1.fill(INF);
  d1[s] = 0;
  
  array<int, INF> d2;
  d2.fill(INF);
  d2[t] = 0;
  
  queue<int> que;
  que.push(s);
  
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (auto i : G[node]) {
      if (d1[i] == INF) {
        d1[i] = d1[node] + 1;
        que.push(i);
      }
    }
  }
  
  que.push(t);
  
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (auto i : G[node]) {
      if (d2[i] == INF) {
        d2[i] = d2[node] + 1;
        que.push(i);
      }
    }
  }
  
  int shortest = d1[t];
  array<int, INF> r1;
  r1.fill(0);
  array<int, INF> r2;
  r2.fill(0);
  
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
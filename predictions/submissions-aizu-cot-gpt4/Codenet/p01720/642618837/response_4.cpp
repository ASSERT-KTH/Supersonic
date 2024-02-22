#include <functional>
#include <iostream>
#include <queue>
#include <vector>

#define INF (1 << 23)
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int N, M, s, t, u, v;
  scanf("%d", &N);
  scanf("%d", &M);
  scanf("%d", &s);
  s--;
  scanf("%d", &t);
  t--;

  vector<vector<int>> G(N);
  G.reserve(N);

  for (int i = 0; i < M; i++) {
    scanf("%d", &u);
    scanf("%d", &v);
    G[u - 1].emplace_back(v - 1);
    G[v - 1].emplace_back(u - 1);
  }

  vector<int> d1(N, INF);
  d1[s] = 0;
  vector<int> d2(N, INF);
  d2[t] = 0;
  
  queue<int> que;
  que.push(s);
  
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (int i = 0; i < G[node].size(); i++) {
      if (d1[G[node][i]] == INF) {
        d1[G[node][i]] = d1[node] + 1;
        que.push(G[node][i]);
      }
    }
  }
  que.push(t);
  while (!que.empty()) {
    int node = que.front();
    que.pop();
    for (int i = 0; i < G[node].size(); i++) {
      if (d2[G[node][i]] == INF) {
        d2[G[node][i]] = d2[node] + 1;
        que.push(G[node][i]);
      }
    }
  }
  int shortest = d1[t];
  vector<int> r1(shortest - 1, 0);
  vector<int> r2(shortest - 1, 0);
  
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
  printf("%lld\n", ret);
  return 0;
}
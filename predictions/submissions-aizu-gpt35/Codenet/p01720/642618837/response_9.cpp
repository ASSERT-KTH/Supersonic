#include <functional>
#include <iostream>
#include <queue>
#include <vector>
#pragma warning(disable : 4996)
#define INF (1 << 23)
using namespace std;
int main() {
  int N, M, s, t, u, v;
  scanf("%d", &N);
  scanf("%d", &M);
  scanf("%d", &s);
  s--;
  scanf("%d", &t);
  t--;
  vector<vector<int>> G(N);
  vector<int> d1(N, INF);
  vector<int> d2(N, INF);
  vector<int> r1(N, 0);
  vector<int> r2(N, 0);
  queue<int> que;
  for (int i = 0; i < M; i++) {
    scanf("%d", &u);
    scanf("%d", &v);
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }
  d1[s] = 0;
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
  d2[t] = 0;
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
  for (int i = 0; i < N; i++) {
    if (d1[i] + d2[i] == shortest) {
      r1[d1[i]]++;
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

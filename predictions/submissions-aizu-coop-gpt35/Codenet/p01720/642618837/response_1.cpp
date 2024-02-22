#include <cstdio>
#include <vector>
#include <queue>
#include <list>
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

  vector<list<int>> G(N); // Use adjacency list instead of vector of vectors

  for (int i = 0; i < M; i++) {
    scanf("%d", &u);
    scanf("%d", &v);
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }

  vector<int> d1(N, INF);
  vector<int> d2(N, INF);
  d1[s] = 0;
  d2[t] = 0;

  queue<int> que;
  que.push(s);

  while (!que.empty()) {
    int node = que.front();
    que.pop();

    for (int neighbor : G[node]) { // Use range-based for loop for neighbors
      if (d1[neighbor] == INF) {
        d1[neighbor] = d1[node] + 1;
        que.push(neighbor);
      }
    }
  }

  que.push(t);

  while (!que.empty()) {
    int node = que.front();
    que.pop();

    for (int neighbor : G[node]) { // Use range-based for loop for neighbors
      if (d2[neighbor] == INF) {
        d2[neighbor] = d2[node] + 1;
        que.push(neighbor);
      }
    }
  }

  int shortest = d1[t];

  vector<int> r1(shortest - 1, 0); // Resize r1 and r2 upfront
  vector<int> r2(shortest - 1, 0);

  for (int i = 0; i < N; i++) {
    if (d1[i] < shortest - 1) {
      r1[d1[i]]++;
    }
  }

  for (int i = 0; i < N; i++) {
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
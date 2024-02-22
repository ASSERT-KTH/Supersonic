#include <iostream>
#include <queue>
#include <vector>

#define INF (1 << 23)

using namespace std;

int main() {
  int N, M, s, t, u, v;
  cin >> N >> M >> s >> t;
  s--;
  t--;

  vector<vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }

  vector<int> d1(N, INF);
  d1[s] = 0;
  vector<int> d2(N, INF);
  d2[t] = 0;

  queue<int> que;
  que.push(s);
  que.push(t);

  while (!que.empty()) {
    int node = que.front();
    que.pop();
    vector<int>& d = (node == s) ? d1 : d2;

    for (int i = 0; i < G[node].size(); i++) {
      int neighbor = G[node][i];
      if (d[neighbor] == INF) {
        d[neighbor] = d[node] + 1;
        que.push(neighbor);
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
    int product = r1[i] * r2[shortest - i - 2];
    ret += product;
  }

  cout << ret << endl;

  return 0;
}
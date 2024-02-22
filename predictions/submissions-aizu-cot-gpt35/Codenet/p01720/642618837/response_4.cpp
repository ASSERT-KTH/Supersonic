#include <iostream>
#include <vector>

const int INF = (1 << 23);

int main() {
  int N, M, s, t, u, v;
  std::cin >> N >> M >> s >> t;
  s--;
  t--;

  std::vector<std::vector<int>> G(N);
  for (int i = 0; i < M; i++) {
    std::cin >> u >> v;
    G[u - 1].push_back(v - 1);
    G[v - 1].push_back(u - 1);
  }

  std::vector<int> d1(N, INF);
  d1[s] = 0;
  std::vector<int> d2(N, INF);
  d2[t] = 0;

  std::vector<int> r1, r2;
  int shortest = d1[t];

  for (int dist = 0; dist < shortest - 1; dist++) {
    r1.push_back(0);
    r2.push_back(0);
  }

  std::vector<int> queue1, queue2;
  queue1.push_back(s);
  queue2.push_back(t);

  for (int dist = 0; dist < shortest - 1; dist++) {
    for (int i = 0; i < queue1.size(); i++) {
      int node = queue1[i];
      for (int neighbor : G[node]) {
        if (d1[neighbor] == INF) {
          d1[neighbor] = d1[node] + 1;
          queue1.push_back(neighbor);
        }
      }
    }

    for (int i = 0; i < queue2.size(); i++) {
      int node = queue2[i];
      for (int neighbor : G[node]) {
        if (d2[neighbor] == INF) {
          d2[neighbor] = d2[node] + 1;
          queue2.push_back(neighbor);
        }
      }
    }
  }

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

  std::cout << ret << std::endl;
  
  return 0;
}
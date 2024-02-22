#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <stack>

class t_sort {
public:
  int n;
  std::vector<int> deg;
  std::vector<std::vector<int>> G;
  void init(int N) {
    n = N;
    deg.resize(n);
    G.resize(n);
  }
  void add_edge(int from, int to) {
    G[from].push_back(to);
    deg[to]++;
  }
  void tsort() {
    std::deque<int> q;
    int missing = 0;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        q.push_back(i);
      }
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop_front();
      std::cout << v + 1 << std::endl;
      for (int u : G[v]) {
        if (--deg[u] == 0) {
          q.push_back(u);
        }
        else {
          missing = 1;
        }
      }
    }
    std::cout << missing << std::endl;
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  t_sort t;
  t.init(n);
  std::map<std::pair<int, int>, int> mp;
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--;
    y--;
    t.add_edge(x, y);
    mp[std::make_pair(x, y)] = 1;
  }
  t.tsort();
  return 0;
}
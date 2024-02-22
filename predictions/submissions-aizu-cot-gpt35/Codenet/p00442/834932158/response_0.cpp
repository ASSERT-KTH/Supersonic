#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

class t_sort {
public:
  int n;
  vector<int> ans, deg;
  vector<vector<int>> G;
  vector<int> res; // Store the result directly
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
    queue<int> q; // Use queue instead of stack
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) q.push(i);
    }
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      ans.push_back(v);
      res.push_back(v + 1); // Store the result directly
      for (int u : G[v]) {
        if (--deg[u] == 0) q.push(u);
      }
    }
  }
};

int main() {
  int n, m;
  cin >> n >> m;

  t_sort t;
  t.init(n);
  map<pair<int, int>, int> mp;

  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    t.add_edge(x, y);
    mp[make_pair(x, y)] = 1;
  }

  t.tsort();

  for (int i = 0; i < n; i++) {
    cout << t.res[i] << endl;
  }

  int res = 1;
  for (int i = 0; i < n - 1; i++) {
    if (mp[make_pair(t.ans[i], t.ans[i + 1])] == 0) {
      res = 0;
      break;
    }
  }

  cout << (res == 1 ? 0 : 1) << endl;

  return 0;
}
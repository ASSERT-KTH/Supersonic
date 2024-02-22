#include <iostream>
#include <vector>
#include <deque>

using namespace std;

class t_sort {
public:
  int n;
  vector<int> ans, deg;
  vector<vector<int>> G;
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
    deque<int> dq;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) dq.push_back(i);
    }
    while (!dq.empty()) {
      int v = dq.front();
      dq.pop_front();
      ans.push_back(v);
      for (int i = 0; i < G[v].size(); i++) {
        if (--deg[G[v][i]] == 0) dq.push_back(G[v][i]);
      }
    }
  }
};

int main() {
  int n, m;
  cin >> n >> m;
  t_sort t;
  t.init(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    t.add_edge(x, y);
  }
  t.tsort();
  vector<int> ans = t.ans;
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << endl;
  }
  int res = 1;
  for (int i = 0; i < n - 1; i++) {
    if (t.G[ans[i]].size() == 0 || t.G[ans[i]][0] != ans[i + 1]) {
      res = 0;
      break;
    }
  }
  cout << (res == 1 ? 0 : 1) << endl;
  return 0;
}
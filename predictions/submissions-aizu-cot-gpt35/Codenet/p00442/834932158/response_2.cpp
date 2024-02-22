#include <iostream>
#include <vector>
#include <deque>
#include <stack>
#include <map>
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
  void tsort(vector<int>& sorted) {
    stack<int> st;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) st.push(i);
    }
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      sorted.push_back(v);
      for (int i = 0; i < G[v].size(); i++) {
        if (--deg[G[v][i]] == 0) st.push(G[v][i]);
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
  vector<int> ans;
  t.tsort(ans);
  for (int i = 0; i < n; i++) {
    cout << ans[i] + 1 << endl;
  }
  int res = 1;
  for (int i = 0; i < n - 1; i++) {
    if (t.G[ans[i]].end() == find(t.G[ans[i]].begin(), t.G[ans[i]].end(), ans[i + 1])) {
      res = 0;
      break;
    }
  }
  cout << (res == 1 ? 0 : 1) << endl;
  return 0;
}
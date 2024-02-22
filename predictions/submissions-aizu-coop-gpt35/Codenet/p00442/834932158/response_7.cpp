#include <iostream>
#include <vector>
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
    vector<int> st;
    st.reserve(n);
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        st.push_back(i);
      }
    }
    while (!st.empty()) {
      int v = st.back();
      st.pop_back();
      ans.push_back(v);
      for (int adj : G[v]) {
        if (--deg[adj] == 0) {
          st.push_back(adj);
        }
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
    if (t.G[ans[i]][ans[i + 1]] == 0) {
      res = 0;
      break;
    }
  }
  cout << (res == 1 ? 0 : 1) << endl;
  return 0;
}
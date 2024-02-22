#include <iostream>
#include <vector>
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
  bool tsort() {
    stack<int> st;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) {
        st.push(i);
      }
    }
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      ans.push_back(v);
      for (int i = 0; i < G[v].size(); i++) {
        if (--deg[G[v][i]] == 0) {
          st.push(G[v][i]);
        }
      }
    }
    return ans.size() == n;
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
  if (t.tsort()) {
    for (int i = 0; i < n; i++) {
      cout << t.ans[i] + 1 << endl;
    }
    cout << 0 << endl;
  } else {
    cout << 1 << endl;
  }
  return 0;
}
#include <iostream>
#include <vector>
#include <deque>
#include <map>
#include <stack>
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
    G[from].emplace_back(to);
    deg[to]++;
  }
  void tsort() {
    stack<int> st;
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) st.push(i);
    }
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      ans.emplace_back(v);
      for (int i = 0; i < G[v].size(); i++) {
        if (--deg[G[v][i]] == 0) st.push(G[v][i]);
      }
    }
  }
};

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  t_sort t;
  t.init(n);
  map<pair<int, int>, int> mp;
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    t.add_edge(x, y);
    mp[make_pair(x, y)] = 1;
  }
  t.tsort();
  vector<int> ans = t.ans;
  for (int i = 0; i < n; i++) {
    printf("%d\n", ans[i] + 1);
  }
  int res = 1;
  for (int i = 0; i < n - 1; i++) {
    if (mp[make_pair(ans[i], ans[i + 1])] == 0) {
      res = 0;
      break;
    }
  }
  printf("%d\n", res == 1 ? 0 : 1);
  return 0;
}
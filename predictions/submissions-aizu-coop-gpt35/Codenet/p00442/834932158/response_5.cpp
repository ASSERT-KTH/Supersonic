#include <bits/stdc++.h>
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
    for (int i = 0; i < n; i++) {
      if (deg[i] == 0) st.push_back(i);
    }
    while (!st.empty()) {
      int v = st.back();
      st.pop_back();
      ans.push_back(v);
      for (int i = 0; i < G[v].size(); i++) {
        if (--deg[G[v][i]] == 0) st.push_back(G[v][i]);
      }
    }
  }
};

unordered_map<pair<int, int>, int> mp;

int main() {
  int n, m;
  scanf("%lld%lld", &n, &m);
  t_sort t;
  t.init(n);
  for (int i = 0; i < m; i++) {
    int x, y;
    scanf("%lld%lld", &x, &y);
    x--;
    y--;
    t.add_edge(x, y);
    mp[make_pair(x, y)] = 1;
  }
  t.tsort();
  vector<int> ans = t.ans;
  for (int i = 0; i < n; i++) {
    printf("%lld\n", ans[i] + 1);
  }
  int res = 1;
  for (int i = 0; i < n - 1; i++) {
    if (mp[make_pair(ans[i], ans[i + 1])] == 0) {
      res = 0;
    }
  }
  printf("%lld\n", res == 1 ? 0 : 1);
  return 0;
}
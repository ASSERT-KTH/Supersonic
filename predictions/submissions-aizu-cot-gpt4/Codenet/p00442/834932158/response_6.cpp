#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef vector<int> vi;
const int INF = 1e18 + 7;
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
    stack<int> st;
    for (int i = 0; i < n; i++) if (deg[i] == 0) st.push(i);
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      ans.push_back(v);
      for (int i = 0; i < G[v].size(); i++) if (--deg[G[v][i]] == 0) st.push(G[v][i]);
    }
  }
};
vector<vector<bool>> mp;
signed main() {
  int n, m;
  scanf("%lld%lld", &n, &m);
  t_sort t;
  t.init(n);
  mp.resize(n, vector<bool>(n, false));
  for(int i = 0; i < m; i++) {
    int x, y;
    scanf("%lld%lld", &x, &y);
    x--;
    y--;
    t.add_edge(x, y);
    mp[x][y] = true;
  }
  t.tsort();
  vi ans = t.ans;
  for(int i = 0; i < n; i++) printf("%lld\n", ans[i] + 1LL);
  int res = 1;
  for(int i = 0; i < n - 1; i++) {
    if (mp[ans[i]][ans[i + 1]] == false)
      res = 0;
  }
  printf("%lld\n", res == 1 ? 0 : 1);
  return 0;
}
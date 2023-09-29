#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(v) v.begin(), v.end()
typedef vector<int> vi;
class t_sort {
public:
  int n;
  vi ans, deg;
  vector<vi> G;
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
    queue<int> q;
    for(int i = 0; i < n; i++) if(deg[i] == 0) q.push(i);
    while(!q.empty()) {
      int v = q.front();
      q.pop();
      ans.push_back(v);
      for(auto u : G[v]) {
        if(--deg[u] == 0) q.push(u);
      }
    }
  }
};
signed main() {
  int n, m;
  scanf("%lld%lld", &n, &m);
  t_sort t;
  t.init(n);
  for(int i = 0; i < m; i++) {
    int x, y;
    scanf("%lld%lld", &x, &y);
    x--;
    y--;
    t.add_edge(x, y);
  }
  t.tsort();
  vi ans = t.ans;
  for(auto x : ans) printf("%lld\n", x + 1);
  int res = 1;
  for(int i = 0; i < n - 1; i++) {
    bool f = false;
    for(auto u : t.G[ans[i]]) {
      if(u == ans[i + 1]) f = true;
    }
    if(!f) {
      res = 0;
      break;
    }
  }
  printf("%lld\n", res == 1 ? 0 : 1);
  return 0;
}

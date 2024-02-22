#include <iostream>
#include <vector>
#include <set>
#include <utility>
#include <stack>

using namespace std;

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
    for(int i=0; i<n; i++) 
        if (deg[i] == 0) 
            st.push(i);
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      ans.push_back(v);
      for(int i=0; i<G[v].size(); i++) 
        if (--deg[G[v][i]] == 0) 
            st.push(G[v][i]);
    }
  }
};

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  t_sort t;
  t.init(n);
  set<pair<int, int>> edges;
  for(int i=0; i<m; i++) {
    int x, y;
    cin >> x >> y;
    x--; y--;
    t.add_edge(x, y);
    edges.insert(make_pair(x, y));
  }
  t.tsort();
  vector<int> ans = t.ans;
  for(int i=0; i<n; i++) cout << ans[i] + 1 << "\n";
  int res = 1;
  for(int i=0; i<n-1; i++) {
    if (edges.find(make_pair(ans[i], ans[i + 1])) == edges.end())
      res = 0;
  }
  cout << (res == 1 ? 0 : 1) << "\n";
  return 0;
}
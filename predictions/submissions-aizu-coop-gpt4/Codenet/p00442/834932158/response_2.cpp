#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

// Topological sort class
class t_sort {
public:
  int n;
  vi ans, deg;
  vector<vi> G, edges;
  
  void init(int N) {
    n = N;
    deg.resize(n);
    G.resize(n);
    edges.resize(n, vi(n));
  }
  
  void add_edge(int from, int to) {
    G[from].push_back(to);
    deg[to]++;
    edges[from][to] = 1;
  }
  
  void tsort() {
    stack<int> st;
    for(int i=0; i<n; i++) if (deg[i] == 0) st.push(i);
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      ans.push_back(v);
      for(auto it = G[v].begin(); it != G[v].end(); it++) {
        if (--deg[*it] == 0) st.push(*it);
      }
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  int n, m;
  cin>>n>>m;
  
  t_sort t;
  t.init(n);
  
  for(int i=0; i<m; i++) {
    int x, y;
    cin>>x>>y;
    x--; y--;
    t.add_edge(x, y);
  }
  
  t.tsort();
  
  for(int i=0; i<n; i++) cout<<(t.ans[i] + 1)<<"\n";
  
  return 0;
}
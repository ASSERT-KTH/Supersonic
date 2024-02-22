#include <bits/stdc++.h>
using namespace std;
#define int long long
#define repi(i, m, n) for (int i = m; i < n; i++)
#define rep(i, n) repi(i, 0, n)
typedef pair<int, int> P;
const int inf = 1e9 + 7;
const int INF = 1e18 + 7;

class t_sort {
public:
  int n;
  vector<int> ans, deg;
  vector<vector<int>> G;
  vector<vector<bool>> adjacency_matrix;  // New adjacency matrix
  bool isValid = true;  // Flag to check if the sort is valid
  
  void init(int N) {
    n = N;
    deg.resize(n);
    G.resize(n);
    adjacency_matrix.resize(n, vector<bool>(n, false));  // Initialize adjacency matrix
  }
  
  void add_edge(int from, int to) {
    G[from].push_back(to);
    deg[to]++;
    adjacency_matrix[from][to] = true;  // Set the adjacency matrix entry to true
  }
  
  void tsort() {
    stack<int> st;
    rep(i, n) if (deg[i] == 0) st.push(i);
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      ans.push_back(v);
      rep(i, G[v].size()) {
        if (--deg[G[v][i]] == 0) {
          if (i < G[v].size() - 1 && !adjacency_matrix[v][G[v][i + 1]]) {
            isValid = false;  // If the next vertex in the sorted order is not adjacent, set isValid to false
          }
          st.push(G[v][i]);
        }
      }
    }
  }
};

signed main() {
  int n, m;
  scanf("%lld%lld", &n, &m);
  
  t_sort t;
  t.init(n);
  
  rep(i, m) {
    int x, y;
    scanf("%lld%lld", &x, &y);
    x--; y--;
    t.add_edge(x, y);
  }
  
  t.tsort();
  
  rep(i, n) printf("%lld\n", t.ans[i] + 1);
  
  printf("%lld\n", t.isValid ? 0 : 1);
  
  return 0;
}
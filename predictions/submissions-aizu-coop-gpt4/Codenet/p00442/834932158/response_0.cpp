#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <utility>

const int mod = 1e9 + 7;

inline void ADD(int& a, int b) { a = (a + b) % mod; }
inline void SUB(int& a, int b) { a = (a + mod - b) % mod; }
inline void MUL(int& a, int b) { a = (a * b) % mod; }

using namespace std;

class t_sort {
public:
  int n;
  vector<int> deg;
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
    for(int i = 0; i < n; i++) if (deg[i] == 0) st.push(i);
    while (!st.empty()) {
      int v = st.top();
      st.pop();
      cout << v+1 << "\n";
      for(int i = 0; i < G[v].size(); i++) if (--deg[G[v][i]] == 0) st.push(G[v][i]);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m;
  cin >> n >> m;
  t_sort t;
  t.init(n);
  vector<pair<int, int>> edges;
  for(int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--;
    y--;
    t.add_edge(x, y);
    edges.emplace_back(x, y);
  }
  
  // sort the edges based on the first element and then the second
  sort(edges.begin(), edges.end());

  t.tsort();
  int res = 1;
  for(int i = 0; i < n - 1; i++) {
    // use binary_search to find the pair in the sorted vector
    if (!binary_search(edges.begin(), edges.end(), make_pair(i, i+1)))
      res = 0;
  }
  cout << (res == 1 ? 0 : 1) << "\n";
  return 0;
}
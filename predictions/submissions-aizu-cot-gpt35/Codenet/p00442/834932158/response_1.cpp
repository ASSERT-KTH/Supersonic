#include <iostream>
#include <vector>
#include <stack>

class t_sort {
public:
  int n;
  std::vector<int> ans, deg;
  std::vector<std::vector<int>> G;
  
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
    std::stack<int> st;
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
        int u = G[v][i];
        if (--deg[u] == 0) {
          st.push(u);
        }
      }
    }
  }
};

int main() {
  int n, m;
  std::cin >> n >> m;
  
  t_sort t;
  t.init(n);
  
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    x--;
    y--;
    t.add_edge(x, y);
  }
  
  t.tsort();
  
  std::vector<int> ans = t.ans;
  
  std::copy(ans.begin(), ans.end(), std::ostream_iterator<int>(std::cout, "\n"));
  
  int res = 1;
  for (int i = 0; i < n - 1; i++) {
    if (t.deg[ans[i + 1]] != 1) {
      res = 0;
      break;
    }
  }
  
  std::cout << (res == 1 ? 0 : 1) << std::endl;
  
  return 0;
}
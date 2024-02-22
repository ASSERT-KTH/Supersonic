#include <vector>
#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int, int> P;

const int inf = 1e9 + 7;
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
    queue<int> q;
    for (int i = 0; i < n; i++) if (deg[i] == 0) q.push(i);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      ans.push_back(v);
      for (int i = 0; i < G[v].size(); i++) if (--deg[G[v][i]] == 0) q.push(G[v][i]);
    }
  }
};

vector<vector<bool>> adjMatrix;

int main() {
  int n, m;
  scanf("%d%d", &n, &m);
  t_sort t;
  t.init(n);
  adjMatrix.resize(n, vector<bool>(n, false));
  for(int i = 0; i < m; i++) {
    int x, y;
    scanf("%d%d", &x, &y);
    x--;
    y--;
    t.add_edge(x, y);
    adjMatrix[x][y] = true;
  }
  t.tsort();
  vector<int> ans = t.ans;
  for(int i = 0; i < n; i++) printf("%d\n", ans[i] + 1);
  int res = 1;
  for(int i = 0; i < n - 1; i++) {
    if (adjMatrix[ans[i]][ans[i + 1]] == false)
      res = 0;
  }
  printf("%d\n", res == 1 ? 0 : 1);
  return 0;
}
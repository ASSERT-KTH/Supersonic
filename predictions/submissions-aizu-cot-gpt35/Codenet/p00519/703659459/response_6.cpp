#include <iostream>
#include <vector>
#include <limits>
using namespace std;

const int INF = numeric_limits<int>::max();

vector<int> pass[6000];
int n, k;
vector<int> c;
vector<int> r;
vector<int> d;
vector<bool> used;

void dfs(int v, int f, int end) {
  vector<bool> visited(n, false);
  visited[v] = true;
  d[v] = 0;
  vector<int> stack;
  stack.push_back(v);

  while (!stack.empty()) {
    int u = stack.back();
    stack.pop_back();

    for (int i = 0; i < pass[u].size(); i++) {
      int next = pass[u][i];
      if (!visited[next]) {
        visited[next] = true;
        d[next] = min(d[next], d[u] + c[u]);
        if (f + 1 < end) {
          stack.push_back(next);
        }
      }
    }
  }
}

int dijk(int s, int g) {
  d.assign(n, INF);
  used.assign(n, false);
  d[s] = 0;

  while (true) {
    int v = -1;
    for (int u = 0; u < n; u++) {
      if (!used[u] && (v == -1 || d[u] < d[v])) {
        v = u;
      }
    }
    if (v == -1) {
      break;
    }
    used[v] = true;

    for (int i = 0; i < pass[v].size(); i++) {
      dfs(pass[v][i], 1, r[v]);
    }
  }
  return d[g];
}

int main() {
  cin >> n >> k;

  c.resize(n);
  r.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i] >> r[i];
  }

  for (int i = 0; i < k; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    pass[a].push_back(b);
    pass[b].push_back(a);
  }

  cout << dijk(0, n - 1) << endl;
  return 0;
}
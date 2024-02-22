#include <iostream>
#include <vector>
#include <set>
#include <climits>

typedef std::vector<int> vi;
typedef std::pair<int, int> pii;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
#define pb push_back
#define INF INT_MAX

std::vector<std::set<int>> pass; // Use vector of sets instead of array of vectors
int n, k;
std::vector<int> c;
std::vector<int> r;
std::vector<int> d;
std::vector<bool> used;

void dfs(int v, int u, int f, int end, std::vector<bool>& visited) {
  if (visited[u])
    return;
  visited[u] = true;
  d[u] = std::min(d[u], d[v] + c[v]);
  if (f >= end)
    return;
  int passSize = pass[u].size(); // Store the size of pass[u] in a variable
  for (int i = 0; i < passSize; i++) { // Use variable as loop condition
    dfs(v, *std::next(pass[u].begin(), i), f + 1, end, visited);
  }
}

int dijk(int s, int g) {
  d.assign(n, INF); // Use assign instead of rep
  used.assign(n, false);
  d[s] = 0;
  while (true) {
    int v = -1;
    for (int u = 0; u < n; u++) { // Use for loop instead of rep
      if (!used[u] && (v == -1 || d[u] < d[v]))
        v = u;
    }
    if (v == -1)
      break;
    used[v] = true;
    std::vector<bool> visited(n, false);
    for (int i : pass[v]) {
      dfs(v, i, 1, r[v], visited);
    }
  }
  return d[g];
}

int main() {
  std::cin >> n >> k;
  c.resize(n);
  r.resize(n);
  rep(i, n) std::cin >> c[i] >> r[i];
  pass.resize(n);
  rep(i, k) {
    int a, b;
    std::cin >> a >> b;
    a--, b--;
    pass[a].insert(b);
    pass[b].insert(a);
  }
  std::cout << dijk(0, n - 1) << std::endl;
}
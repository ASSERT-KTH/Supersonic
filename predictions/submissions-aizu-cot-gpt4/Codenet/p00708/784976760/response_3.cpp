#include <algorithm>
#include <cstdio>
using namespace std;
#define M 9999
int parent[M], a[M], b[M];
pair<double, int> node[M];
int root(int a) { return parent[a] == a ? a : parent[a] = root(parent[a]); }
int unite(int a, int b) {
  int x = root(a), y = root(b);
  if (x == y)
    return 0;
  parent[x] = y;
  return 1;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, m, n;
  double x, y, z, r;
  for (; cin >> n, n;) {
    for (i = 0; i < n; i++)
      parent[i] = i;
    for (m = i = 0; i < n; i++)
      for (j = i + 1; j < n; j++) {
        cin >> x >> y >> z >> r;
        double d = (x - y) * (x - y) + (z - r) * (z - r);
        if (d <= 0)
          unite(i, j);
        else
          a[m] = i, b[m] = j, node[m].first = d, node[m++].second = m;
      }
    sort(node, node + m);
    for (x = i = 0; i < m; i++)
      if (unite(a[node[i].second], b[node[i].second]))
        x += node[i].first;
    cout << x << "\n";
  }
}
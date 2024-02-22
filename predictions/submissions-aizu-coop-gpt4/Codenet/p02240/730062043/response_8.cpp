#include <iostream>
#include <vector>
using namespace std;

int find(vector<int>& parent, int x) {
  int root = x;
  while (root != parent[root])
    root = parent[root];
  while (x != root) {
    int next = parent[x];
    parent[x] = root;
    x = next;
  }
  return root;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<int> parent(n), rank(n, 0);
  for (int i = 0; i < n; ++i)
    parent[i] = i;

  for (int i = 0; i < m; ++i) {
    int s, t;
    cin >> s >> t;
    s = find(parent, s);
    t = find(parent, t);
    if (s != t) {
      if (rank[s] < rank[t])
        parent[s] = t;
      else {
        parent[t] = s;
        if (rank[s] == rank[t])
          rank[s]++;
      }
    }
  }

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int s, t;
    cin >> s >> t;
    if (find(parent, s) == find(parent, t))
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
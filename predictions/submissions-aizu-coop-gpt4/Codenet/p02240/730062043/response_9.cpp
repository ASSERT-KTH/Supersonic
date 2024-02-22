#include <stdio.h>
#include <vector>
using namespace std;

vector<int> parent, rank;

int find(int x) {
  if (x != parent[x]) {
    parent[x] = find(parent[x]); // path compression
  }
  return parent[x];
}

int main() {
  int n, m, s, t, q;
  scanf("%d %d", &n, &m);

  parent.resize(n);
  rank.resize(n, 0);

  for (int i = 0; i < n; i++) {
    parent[i] = i;
  }

  for (int i = 0; i < m; i++) {
    scanf("%d %d", &s, &t);
    s = find(s);
    t = find(t);
    if (s != t) {
      if (rank[s] < rank[t])
        parent[s] = parent[t];
      else {
        parent[t] = parent[s];
        if (rank[s] == rank[t])
          rank[s]++;
      }
    }
  }

  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    scanf("%d %d", &s, &t);
    if (find(s) == find(t))
      printf("yes\n");
    else
      printf("no\n");
  }

  return 0;
}
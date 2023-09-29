#include <iostream>
#include <vector>
using namespace std;

vector<int> join, rankk;

int find(int x) {
  if (x != join[x])
    join[x] = find(join[x]);
  return join[x];
}

void unite(int x, int y) {
  x = find(x);
  y = find(y);
  if (x != y) {
    if (rankk[x] < rankk[y]) {
      join[x] = y;
    } else {
      join[y] = x;
      if (rankk[x] == rankk[y])
        rankk[x]++;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, s, t, q;
  cin >> n >> m;
  join.resize(n);
  rankk.resize(n, 0);
  for (int i = 0; i < n; ++i)
    join[i] = i;
  
  while (m--) {
    cin >> s >> t;
    unite(s, t);
  }

  cin >> q;
  while (q--) {
    cin >> s >> t;
    if (find(s) == find(t))
      cout << "yes\n";
    else
      cout << "no\n";
  }
}
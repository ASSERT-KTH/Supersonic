#include <iostream>
using namespace std;

int find(int join[], int x) {
  if (join[x] != x)
    join[x] = find(join, join[x]);
  return join[x];
}

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m, join[100000], num[100000], s, t;
  cin >> n >> m;
  for (int i = 0; i < n; ++i) {
    join[i] = i;
    num[i] = 0;
  }
  for (int i = 0; i < m; ++i) {
    cin >> s >> t;
    s = find(join, s);
    t = find(join, t);
    if (s != t) {
      if (num[s] < num[t])
        join[s] = t;
      else {
        join[t] = s;
        if (num[s] == num[t])
          ++num[s];
      }
    }
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> s >> t;
    if (find(join, s) == find(join, t))
      cout << "yes\n";
    else
      cout << "no\n";
  }
  return 0;
}
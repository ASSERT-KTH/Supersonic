#include <iostream>
using namespace std;

int find(int join[], int x) {
  if (x == join[x])
    return x;
  return join[x] = find(join, join[x]);
}

int main(int argc, char *argv[]) {
  int n, m, join[100000], s, t;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    join[i] = i;
  }

  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    s = find(join, s);
    t = find(join, t);
    if (s != t) {
      join[s] = t;
    }
  }

  int q;
  cin >> q;

  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (find(join, s) == find(join, t))
      cout << "yes\n";
    else
      cout << "no\n";
  }
}
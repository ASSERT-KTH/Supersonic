#include <iostream>
using namespace std;

int find(int join[], int x) {
  while (x != join[x]) {
    join[x] = join[join[x]]; // Path compression
    x = join[x];
  }
  return x;
}

int main(int argc, char *argv[]) {
  int n, m, join[100000], num[100000], s, t;
  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    join[i] = i;
    num[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    int root_s = find(join, s);
    int root_t = find(join, t);

    if (root_s != root_t) {
      if (num[root_s] < num[root_t])
        join[root_s] = join[root_t];
      else {
        join[root_t] = join[root_s];
        if (num[root_s] == num[root_t])
          num[root_s]++;
      }
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
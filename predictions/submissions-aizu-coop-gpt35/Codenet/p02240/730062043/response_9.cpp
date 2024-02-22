#include <iostream>
using namespace std;

int find(int join[], int x) {
  int root = x;
  while (root != join[root]) {
    root = join[root];
  }

  // Path compression
  while (x != root) {
    int next = join[x];
    join[x] = root;
    x = next;
  }

  return root;
}

int main(int argc, char *argv[]) {
  int n, m, join[100000], num[100000], s, t;
  cin >> n >> m;

  // Initialize join and num arrays
  for (int i = 0; i < n; i++) {
    join[i] = i;
    num[i] = 0;
  }

  // Perform union operations
  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    s = find(join, s);
    t = find(join, t);
    if (s != t) {
      // Union by rank
      if (num[s] < num[t])
        join[s] = t;
      else {
        join[t] = s;
        if (num[s] == num[t])
          num[s]++;
      }
    }
  }

  int q;
  cin >> q;

  // Perform find operations
  for (int i = 0; i < q; i++) {
    cin >> s >> t;
    if (find(join, s) == find(join, t))
      cout << "yes\n";
    else
      cout << "no\n";
  }
}
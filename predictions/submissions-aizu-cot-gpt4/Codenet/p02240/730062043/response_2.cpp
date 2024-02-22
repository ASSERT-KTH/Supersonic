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
  for (int i = 0; i < n; i++) {
    join[i] = i;
    num[i] = 0;
  }
  for (int i = 0; i < m; i++) {
    cin >> s >> t;
    s = find(join, s);
    t = find(join, t);
    if (s != t) {
      if (num[s] < num[t])
        join[s] = join[t];
      else {
        join[t] = join[s];
        if (num[s] == num[t])
          num[s]++;
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
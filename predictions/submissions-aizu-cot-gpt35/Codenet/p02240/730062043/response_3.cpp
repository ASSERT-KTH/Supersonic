#include <iostream>
#include <vector>

int find(std::vector<int>& join, int x) {
  if (x != join[x]) {
    join[x] = find(join, join[x]); // Path compression
  }
  return join[x];
}

int main() {
  int n, m, q, s, t;
  std::cin >> n >> m;

  std::vector<int> join(n), num(n, 0);
  for (int i = 0; i < n; i++) {
    join[i] = i;
  }

  for (int i = 0; i < m; i++) {
    std::cin >> s >> t;
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

  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> s >> t;
    if (find(join, s) == find(join, t))
      std::cout << "yes\n";
    else
      std::cout << "no\n";
  }
}
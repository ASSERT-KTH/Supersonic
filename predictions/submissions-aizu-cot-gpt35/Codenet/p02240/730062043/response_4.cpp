#include <iostream>
#include <vector>

int find(std::vector<int>& join, int x) {
  if (x == join[x])
    return x;
  
  return join[x] = find(join, join[x]);
}

int main(int argc, char* argv[]) {
  std::ios_base::sync_with_stdio(false);

  int n, m, s, t;
  std::cin >> n >> m;

  std::vector<int> join(n), num(n);
  for (int i = 0; i < n; i++) {
    join[i] = i;
    num[i] = 0;
  }

  for (int i = 0; i < m; i++) {
    std::cin >> s >> t;
    s = find(join, s);
    t = find(join, t);
    if (s != t) {
      if (num[s] < num[t]) {
        join[s] = t;
      } else {
        join[t] = s;
        if (num[s] == num[t]) {
          num[s]++;
        }
      }
    }
  }

  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    std::cin >> s >> t;
    if (find(join, s) == find(join, t)) {
      std::cout << "yes\n";
    } else {
      std::cout << "no\n";
    }
  }

  return 0;
}
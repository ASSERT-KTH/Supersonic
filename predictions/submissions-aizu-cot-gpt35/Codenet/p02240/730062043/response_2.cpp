#include <iostream>

int find(int join[], int x) {
  if (x == join[x])
    return x;
  return find(join, join[x]);
}

int main(int argc, char* argv[]) {
  int n, m, s, t;
  std::cin >> n >> m;
  
  int* join = new int[n];
  int* num = new int[n];
  
  for (int i = 0; i < n; i++) {
    join[i] = i;
    num[i] = 0;
  }
  
  for (int i = 0; i < m; i++) {
    std::cin >> s >> t;
    s = find(join, s);
    t = find(join, t);
    if (s != t) {
      join[s] = join[t];
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
  
  delete[] join;
  delete[] num;
  
  return 0;
}
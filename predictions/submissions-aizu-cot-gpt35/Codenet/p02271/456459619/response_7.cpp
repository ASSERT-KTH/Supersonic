#include <iostream>
#include <vector>

bool solve(const std::vector<int>& N, int i, int m) {
  if (i == 0) {
    return m == 0;
  }
  return solve(N, i - 1, m - N[i - 1]) || solve(N, i - 1, m);
}

int main() {
  int n;
  std::cin >> n;
  
  std::vector<int> N(n);
  for (int i = 0; i < n; i++) {
    std::cin >> N[i];
  }
  
  int t;
  std::cin >> t;
  
  for (int i = 0; i < t; i++) {
    int p;
    std::cin >> p;
    
    if (solve(N, n, p)) {
      std::cout << "yes" << std::endl;
    } else {
      std::cout << "no" << std::endl;
    }
  }

  return 0;
}
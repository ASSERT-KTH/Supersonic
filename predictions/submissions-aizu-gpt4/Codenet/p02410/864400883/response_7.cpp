#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int n, m;
  std::cin >> n >> m;

  std::vector<std::vector<int>> a(n, std::vector<int>(m));
  std::vector<int> b(m);

  for(auto &i : a)
    for(auto &j : i)
      std::cin >> j;
  
  for(auto &i : b)
    std::cin >> i;

  for(const auto &i : a) {
    int c = 0;
    for(int j = 0; j < m; ++j) 
      c += i[j] * b[j];
    
    std::cout << c << '\n';
  }
  
  return 0;
}
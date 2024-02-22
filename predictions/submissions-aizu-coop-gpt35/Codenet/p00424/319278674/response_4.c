#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<int> t;
  
  while (std::cin >> n) {
    t.resize(n);
    
    for (int i = 0; i < n; ++i) {
      char c;
      std::cin >> i >> c;
      t[i] = c;
    }
    
    std::cin >> n;
    
    for (int i = 0; i < n; ++i) {
      char c;
      std::cin >> i;
      putchar(t[i]);
    }
    
    std::cout << std::endl;
  }
  
  return 0;
}
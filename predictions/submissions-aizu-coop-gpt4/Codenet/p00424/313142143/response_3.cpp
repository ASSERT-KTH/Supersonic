#include <iostream>

int main() {
  int n;
  
  while(std::cin >> n, n) {
    int d[256] = {};
    for (char a, b; n--; d[a] = b - a) {
      std::cin >> a >> b;
    }
    
    std::cin >> n;
    for (char a; n--; std::putchar(a + d[a])) {
      std::cin >> a;
    }
    std::puts("");
  }
}
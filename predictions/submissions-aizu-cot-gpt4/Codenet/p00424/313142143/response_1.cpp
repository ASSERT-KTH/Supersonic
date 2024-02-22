#include <iostream>
#include <cstring>

int main() {
  int n;
  int d[256];
  char a, b;
  
  while(std::cin >> n && n) {
    memset(d, 0, sizeof(d));
    for (int i = 0; i < n; ++i) {
      std::cin >> a >> b;
      d[a] = b - a;
    }
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
      std::cin >> a;
      std::cout << char(a + d[a]);
    }
    std::cout << "\n";
  }
}
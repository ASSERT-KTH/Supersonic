#include <iostream>
#include <string>

int main() {
  int h, w;
  while(std::cin >> h >> w && (h != 0 || w != 0)) {
    std::cout << std::string(w, '#') << '\n';
  }
  return 0;
}
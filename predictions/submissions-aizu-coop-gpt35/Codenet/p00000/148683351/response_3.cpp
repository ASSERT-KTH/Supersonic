#include <iostream>
#include <sstream>

int main() {
  for (int i = 1; i <= 9; i++) {
    std::ostringstream oss;
    for (int j = 1; j <= 9; j++) {
      oss << i << "x" << j << "=" << i * j << '\n';
    }
    std::cout << oss.str();
  }
  
  return 0;
}
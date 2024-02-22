#include <iostream>

int main() {
  int a, b, c, d;
  std::cin >> a >> b >> c >> d;
  
  int minVal = std::min(std::min(a, b), std::min(c, d));
  int ans = a + b + c + d - minVal;
  
  std::cout << ans << std::endl;
  return 0;
}
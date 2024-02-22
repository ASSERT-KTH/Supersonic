#include <iostream>

int main() {
  int a, b, c, d, e, f;
  
  std::cin >> a >> b >> c >> d >> e >> f;
  
  // Compute the sum of the four smallest numbers and the maximum of the last two numbers
  int min_ab = (a < b) ? a : b;
  int min_cd = (c < d) ? c : d;
  int min_abcd = (min_ab < min_cd) ? min_ab : min_cd;
  
  int ans = a + b + c + d - min_abcd + ((e > f) ? e : f);
  
  std::cout << ans << std::endl;
  
  return 0;
}
#include <iostream>
int main() {
  int x, y;
  std::ios_base::sync_with_stdio(false); // disable synchronization between C and C++ standard streams
  std::cin.tie(NULL); // untie cin from cout for performance boost
  std::cout.tie(NULL); // untie cout from cin for performance boost
  std::cin >> x;
  y = x * x * x;
  std::cout << y << '\n'; // use single quotes for character literals
  return 0;
}
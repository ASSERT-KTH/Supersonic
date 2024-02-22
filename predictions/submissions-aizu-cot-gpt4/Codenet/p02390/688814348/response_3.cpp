#include <iostream>
int main(void) {
  int S, rem;
  std::cin >> S;
  rem = S % 3600;
  std::cout << S / 3600 << ":" << rem / 60 << ":" << rem % 60 << std::endl;
}
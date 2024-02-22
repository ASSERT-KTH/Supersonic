#include <iostream>

int main(void) {
  int S;
  std::cin >> S;
  int rem = S % 3600;
  std::cout << S / 3600 << ":" << rem / 60 << ":" << rem % 60 << std::endl;
  return 0;
}
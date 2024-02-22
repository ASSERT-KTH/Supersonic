#include <iostream>

const int MAX = 999999;

int main() {
  int n;
  int primeCount = 0;
  
  for (int i = 2; i <= MAX; ++i) {
    bool isPrime = true;
    for (int j = 2; j * j <= i; ++j) {
      if (i % j == 0) {
        isPrime = false;
        break;
      }
    }
    if (isPrime) {
      ++primeCount;
    }
  }
  
  while (std::cin >> n) {
    std::cout << primeCount << std::endl;
  }

  return 0;
}
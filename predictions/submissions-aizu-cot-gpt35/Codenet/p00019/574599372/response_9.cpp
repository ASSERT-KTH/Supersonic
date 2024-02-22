#include <iostream>

unsigned long long factorial(int n) {
  if (n == 0 || n == 1)
    return 1;
  
  unsigned long long result = factorial(n / 2);
  result *= result;
  
  if (n % 2 == 1)
    result *= n;
  
  return result;
}

int main() {
  int n;
  std::cin >> n;
  std::cout << factorial(n) << std::endl;
  return 0;
}
#include <iostream>

long long factorial(int n) {
  if (n == 0 || n == 1) {
    return 1;
  }
  
  long long result = 1;
  for (int i = 2; i <= n; i++) {
    result *= i;
  }
  
  return result;
}

int main() {
  int n;
  std::cin >> n;
  
  long long result = factorial(n);
  std::cout << result << std::endl;
  
  return 0;
}
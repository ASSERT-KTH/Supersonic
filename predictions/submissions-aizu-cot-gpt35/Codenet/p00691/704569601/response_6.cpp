#include <iostream>

long long b_pow(long long x, long long n) {
  long long result = 1;
  while (n > 0) {
    if (n & 1) {
      result *= x;
    }
    x *= x;
    n >>= 1;
  }
  return result;
}

int main() {
  long long z;
  while (std::cin >> z && z) {
    long long ans = 0;
    for (long long x = 1; x <= z; x++) {
      for (long long y = 1; y <= z; y++) {
        long long temp = x * x * x + y * y * y;
        if (temp <= z * z * z && temp > ans) {
          ans = temp;
        }
      }
    }
    std::cout << z * z * z - ans << std::endl;
  }
  return 0;
}
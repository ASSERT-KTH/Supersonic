#include <math.h>
#include <iostream>
#include <vector>
#include <cstring>

int main() {
  const int size = 1000000;
  std::vector<int> num(size, 0);
  num[0] = num[1] = 0;
  const int sqrtSize = static_cast<int>(sqrt(size));
  for (auto i = 2; i < sqrtSize; i++) {
    if (num[i] == 0) {
      for (auto j = i * i; j < size; j += i)
        num[j] = 1;
    }
    num[i + 1] += num[i];
  }
  int n;
  while (std::cin >> n) {
    std::cout << num[n] << "\n";
  }
  return 0;
}

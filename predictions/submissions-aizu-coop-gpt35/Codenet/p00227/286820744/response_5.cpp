#include <algorithm>
#include <iostream>
#include <vector>

#pragma GCC optimize("unroll-loops")

int main() {
  int num, cap, price, i;
  std::vector<int> vegetables;
  
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }

    vegetables.resize(num);

    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables[i] = price;
    }

    std::partial_sort(vegetables.begin(), vegetables.begin() + cap, vegetables.end(), std::greater<int>());

    int sum = 0;

    for (i = 0; i < num; i += cap + 1) {
      sum += vegetables[i];
    }

    std::cout << sum << std::endl;
  }
}
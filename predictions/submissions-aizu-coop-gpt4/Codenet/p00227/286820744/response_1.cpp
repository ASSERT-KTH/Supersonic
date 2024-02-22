#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int num, cap, price;
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }
    std::vector<int> vegetables;
    vegetables.reserve(num);  // Allocate all the necessary memory at once
    for (int i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables.push_back(price);
    }
    sort(vegetables.begin(), vegetables.end(), std::greater<int>());
    int sum = 0;
    for(int i = 0; i < num; i += cap) {
      for(int j = i; j < std::min(i + cap, num) - 1; ++j) {
        sum += vegetables[j];  // Use subscript operator instead of at
      }
    }
    std::cout << sum << std::endl;
  }
}
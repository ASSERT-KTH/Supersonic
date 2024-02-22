#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int num, cap, price, i;
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }
    std::vector<int> vegetables(num);
    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables[i] = price;
    }
    std::partial_sort(vegetables.begin(), vegetables.begin() + cap, vegetables.end(), std::greater<int>());
    int sum = 0;
    int step = cap - 1;
    for (i = 0; i < cap * (num / cap); i += cap) {
      sum += vegetables[i];
    }
    std::cout << sum << std::endl;
  }
}
#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

int main() {
  int num, cap, price, i;
  std::vector<int> vegetables;

  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }

    vegetables.clear();
    vegetables.reserve(num);

    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables.push_back(price);
    }

    std::sort(vegetables.begin(), vegetables.end(), std::greater<int>());

    int sum = 0;
    for (i = 0; i < num; ++i) {
      if ((i + 1) % cap != 0) {
        sum += vegetables[i];
      }
    }

    std::cout << sum << '\n';
  }

  return 0;
}
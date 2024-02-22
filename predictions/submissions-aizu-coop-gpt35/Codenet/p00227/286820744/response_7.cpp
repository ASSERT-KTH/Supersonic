#include <algorithm>
#include <iostream>
#include <vector>

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

    int capIndex = cap - 1;
    int capLargest = vegetables[capIndex];

    for (i = 0; i < num; i += cap) {
      if (vegetables[i] > capLargest) {
        capLargest = vegetables[i];
        capIndex = i;
      }
    }

    int sum = 0;
    for (i = 0; i < num; ++i) {
      if (i != capIndex) {
        sum += vegetables[i];
      }
    }

    std::cout << sum << std::endl;
  }
}
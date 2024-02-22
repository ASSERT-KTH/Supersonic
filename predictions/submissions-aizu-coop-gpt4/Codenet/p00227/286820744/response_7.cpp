#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int num, cap, price;
  std::vector<int> vegetables;

  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }

    vegetables.clear();
    vegetables.reserve(num);

    for (int i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables.push_back(price);
    }

    sort(vegetables.begin(), vegetables.end(), std::greater<int>());

    int sum = 0;
    for (int i = 0; i < num; i += cap) {
      for (int j = i; j < std::min(num, i + cap - 1); ++j) {
        sum += vegetables[j];
      }
    }

    std::cout << sum << "\n";
  }

  return 0;
}
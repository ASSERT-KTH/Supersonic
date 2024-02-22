#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  int num, cap, price;
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }
    std::vector<int> vegetables;
    vegetables.reserve(num);
    for (int i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables.push_back(price);
    }
    sort(vegetables.begin(), vegetables.end(), std::greater<int>());
    int sum = 0;
    for (int i = 0; i < num; ++i) {
      if ((i + 1) % cap != 0) {
        sum += vegetables[i];
      }
    }
    std::cout << sum << std::endl;
  }
}
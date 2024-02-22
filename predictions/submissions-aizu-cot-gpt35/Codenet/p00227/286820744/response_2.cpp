#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int num, cap;
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }

    std::vector<int> vegetables(num);
    for (int i = 0; i < num; ++i) {
      std::cin >> vegetables[i];
    }

    std::sort(vegetables.begin(), vegetables.end());
    std::reverse(vegetables.begin(), vegetables.end());

    int sum = 0;
    for (int i = 0; i < cap * (num / cap); ++i) {
      if (i % cap != cap - 1) {
        sum += vegetables[i];
      }
    }

    std::cout << sum << std::endl;
  }
}
#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int num, cap, price, i;
  std::vector<int> vegetables(1000000); // Assuming maximum possible size
  
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }

    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables[i] = price;
    }

    std::sort(vegetables.begin(), vegetables.begin() + num, std::greater<int>());

    int sum = 0;
    i = 0;
    while (i < num) {
      if ((i + 1) == cap) {
        ++i;
        continue;
      }
      sum += vegetables[i];
      ++i;
    }

    std::cout << sum << std::endl;
  }
}
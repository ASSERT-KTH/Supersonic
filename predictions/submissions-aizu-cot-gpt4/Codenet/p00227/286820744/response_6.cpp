#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int num, cap, price;
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }
    std::vector<int> vegetables(num);
    for (int i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables[i] = price;
    }
    sort(vegetables.begin(), vegetables.end(), std::greater<int>());
    int sum = 0;
    for (int i = 0; i < num; ++i) {
      if (i % cap != (cap - 1)) {
        sum += vegetables[i];
      }
    }
    std::cout << sum << std::endl;
  }
}
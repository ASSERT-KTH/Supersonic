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
    sort(vegetables.begin(), vegetables.end(), std::greater<int>());
    int sum = 0;
    i = 0;
    while (i < num) {
      if (i % cap != cap - 1) {
        sum += vegetables[i];
      }
      ++i;
    }
    std::cout << sum << std::endl;
  }
}
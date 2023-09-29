#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int num, cap, price, i;
  while (std::cin >> num >> cap) {
    std::vector<int> vegetables;
    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables.push_back(price);
    }
    sort(vegetables.begin(), vegetables.end(), std::greater<int>());
    int sum = 0;
    i = 0;
    while (i < num) {
      if ((i + 1) % cap != 0) {
        sum += vegetables.at(i);
      }
      ++i;
    }
    std::cout << sum << std::endl;
  }
}

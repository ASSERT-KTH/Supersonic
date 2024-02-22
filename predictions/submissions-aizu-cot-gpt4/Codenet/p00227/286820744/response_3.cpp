#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int num, cap, price, i;
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }
    std::vector<int> vegetables;
    vegetables.reserve(num);
    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables.push_back(price);
    }
    sort(vegetables.begin(), vegetables.end(), std::greater<int>());
    int sum = 0;
    for (i = 0; i < num; i += i % cap == cap - 1 ? 2 : 1) {
      sum += vegetables[i];
    }
    std::cout << sum << std::endl;
  }
}
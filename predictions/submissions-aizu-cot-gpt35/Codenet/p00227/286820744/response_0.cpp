#include <iostream>
#include <vector>

int main() {
  int cap, price;
  while (std::cin >> cap) {
    if (cap == 0) {
      break;
    }
    std::vector<int> vegetables;
    while (cap--) {
      std::cin >> price;
      vegetables.push_back(price);
    }
    std::sort(vegetables.begin(), vegetables.end(), std::greater<int>());
    int sum = 0;
    int remaining = vegetables.size() - 1;
    for (int i = 0; i < vegetables.size(); ++i) {
      if (remaining) {
        sum += vegetables[i];
        --remaining;
      }
    }
    std::cout << sum << std::endl;
  }
}
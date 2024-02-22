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
    vegetables.reserve(num); // Pre-allocate required space
    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables.push_back(price);
    }
    std::sort(vegetables.begin(), vegetables.end(), std::greater<int>());
    int sum = 0;
    int count = 0; // Counter for number of vegetables added to sum
    for (i = 0; i < cap * (num / cap); ++i) {
      if (count < cap) {
        sum += vegetables[i];
        ++count;
      }
      else {
        count = 0;
      }
    }
    std::cout << sum << std::endl;
  }
}
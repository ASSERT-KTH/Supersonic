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
    vegetables.reserve(num);  // preallocate memory
    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables.push_back(price);
    }
    sort(vegetables.begin(), vegetables.end(), std::greater<int>());

    int sum = 0;
    for (i = 0; i < num; i += cap) {
      for (int j = i; j < std::min(i + cap - 1, num); ++j) {  // skip every cap'th item
        sum += vegetables[j];  // use [] instead of at()
      }
    }
    std::cout << sum << std::endl;
  }
}
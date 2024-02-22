#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios::sync_with_stdio(false);
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
    sort(vegetables.rbegin(), vegetables.rend());
    int sum = 0;
    for (int i = 0; i < num; i += cap) {
      for (int j = i; j < std::min(i+cap-1, num); ++j) {
        sum += vegetables[j];
      }
    }
    std::cout << sum << std::endl;
  }
}
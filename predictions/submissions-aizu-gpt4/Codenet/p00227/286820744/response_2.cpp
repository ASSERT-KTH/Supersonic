#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int num, cap, price;
  while (std::cin >> num >> cap && (num != 0 || cap != 0)) {
    std::vector<int> vegetables(num);
    for (int i = 0; i < num; ++i) {
      std::cin >> vegetables[i];
    }
    std::sort(vegetables.rbegin(), vegetables.rend());
    int sum = 0;
    for (int i = 0; i < num; ++i) {
      if ((i + 1) % cap != 0) {
        sum += vegetables[i];
      }
    }
    std::cout << sum << '\n';
  }
  return 0;
}
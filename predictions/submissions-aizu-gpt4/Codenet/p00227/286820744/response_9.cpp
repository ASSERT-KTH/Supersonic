#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);
  
  int num, cap, price;
  while (std::cin >> num >> cap && (num != 0 || cap != 0)) {
    std::vector<int> vegetables(num);
    for (int &veg : vegetables) {
      std::cin >> veg;
    }
    sort(vegetables.rbegin(), vegetables.rend());
    int sum = 0;
    for (int i = 0; i < num; i += cap) {
      sum += std::accumulate(vegetables.begin() + i, vegetables.begin() + std::min(i + cap - 1, num), 0);
    }
    std::cout << sum << '\n';
  }
}
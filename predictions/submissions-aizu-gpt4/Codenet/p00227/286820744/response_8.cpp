#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int num, cap, price;
  while (std::cin >> num >> cap && (num || cap)) {
    std::vector<int> vegetables(num);
    for (int i = 0; i < num; ++i) {
      std::cin >> vegetables[i];
    }
    sort(vegetables.rbegin(), vegetables.rend());
    int sum = 0;
    for (int i = 0; i < num; i += cap) {
      sum += vegetables[i];
    }
    std::cout << sum << '\n';
  }
}
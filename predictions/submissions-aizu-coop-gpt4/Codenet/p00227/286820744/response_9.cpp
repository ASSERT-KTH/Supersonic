#include <algorithm>
#include <iostream>
#include <vector>
int main() {
  int num, cap;
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }
    std::vector<int> vegetables(num);
    for (int &price : vegetables) {
      std::cin >> price;
    }
    sort(vegetables.begin(), vegetables.end());
    int sum = 0;
    for (int i = 0; i < num; i += cap) {
      for(int j = i; j < std::min(i + cap - 1, num); ++j) {
        sum += vegetables[j];
      }
    }
    std::cout << sum << std::endl;
  }
  return 0;
}
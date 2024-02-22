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
    for (int i = 0; i < num; ++i) {
      std::cin >> vegetables[i];
    }
    
    std::partial_sort(vegetables.begin(), vegetables.begin() + (num % cap), vegetables.end(), std::greater<int>());
    
    int sum = 0;
    for (int i = 0; i < num; i += cap) {
      sum += vegetables[i];
    }
    
    std::cout << sum << std::endl;
  }
  
  return 0;
}
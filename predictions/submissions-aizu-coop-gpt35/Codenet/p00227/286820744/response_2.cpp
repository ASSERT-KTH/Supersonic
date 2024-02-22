#include <algorithm>
#include <iostream>

int main() {
  int num, cap, price, i;
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }
    int* vegetables = new int[num];
    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables[i] = price;
    }
    std::partial_sort(vegetables, vegetables + cap, vegetables + num, std::greater<int>());
    int sum = 0;
    for (i = 0; i < num; i += cap) {
      sum += vegetables[i];
    }
    std::cout << sum << std::endl;
    delete[] vegetables;
  }
}
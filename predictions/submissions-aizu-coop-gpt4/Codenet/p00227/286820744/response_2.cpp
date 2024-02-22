#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int num, cap, price, i, j;
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }
    std::vector<int> vegetables;
    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables.push_back(price);
    }
    sort(vegetables.begin(), vegetables.end(), std::greater<int>());
    int sum = 0;
    i = 0;
    while (i < num) {
      // Loop over 'cap - 1' elements and add them to the sum
      for (j = 0; j < cap - 1 && i < num; ++j, ++i) {
        sum += vegetables.at(i);
      }
      // Skip the 'cap' element
      ++i;
    }
    std::cout << sum << std::endl;
  }
}
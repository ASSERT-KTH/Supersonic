#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int num, cap, price;
  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }
    std::vector<int> vegetables;
    for (int i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables.push_back(price);
    }
    sort(vegetables.begin(), vegetables.end(), std::greater<int>());
    int sum = 0;
    int counter = 0; // Counter for capacity
    for (int i = 0; i < num; ++i) {
      if (counter != cap - 1) { // If the counter has not reached the capacity
        sum += vegetables.at(i);
      } else { // If the counter has reached the capacity
        counter = -1; // Reset the counter
      }
      ++counter;
    }
    std::cout << sum << std::endl;
  }
}
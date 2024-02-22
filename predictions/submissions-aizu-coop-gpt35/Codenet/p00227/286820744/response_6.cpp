#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int num, cap, price, i;
  std::ios_base::sync_with_stdio(false); // Enable faster I/O

  while (std::cin >> num >> cap) {
    if (num == 0 && cap == 0) {
      break;
    }

    std::vector<int> vegetables(num); // Reuse the same vector for each test case

    for (i = 0; i < num; ++i) {
      std::cin >> price;
      vegetables[i] = price;
    }

    std::partial_sort(vegetables.begin(), vegetables.begin() + cap, vegetables.end(), std::greater<int>());

    int sum = 0;

    for (i = 0; i < num; ++i) {
      if ((i + 1) % cap != 0) {
        sum += vegetables[i];
      }
    }

    std::cout << sum << std::endl;
  }
}
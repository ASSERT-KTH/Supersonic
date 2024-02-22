#include <vector>
#include <iostream>

int main() {
  int maxProfit = 1 - 1000000000;
  int Ri = 2000000000;

  int numElements;
  std::cin >> numElements;

  std::vector<int> R(numElements);
  for (int& element : R) {
    std::cin >> element;
  }

  for (const int& element : R) {
    if (maxProfit < element - Ri) {
      maxProfit = element - Ri;
    }
    if (element < Ri) {
      Ri = element;
    }
  }

  std::cout << maxProfit << std::endl;
  return 0;
}
#include <iostream>
#include <vector>
#include <climits>

int main() {
  int maxProfit = INT_MIN;
  int Ri = 2000000000;

  std::vector<int> R;
  int num;
  while (std::cin >> num) {
    R.push_back(num);
    if (maxProfit < num - Ri) {
      maxProfit = num - Ri;
    }
    if (num < Ri) {
      Ri = num;
    }
  }

  std::cout << maxProfit << std::endl;
  return 0;
}
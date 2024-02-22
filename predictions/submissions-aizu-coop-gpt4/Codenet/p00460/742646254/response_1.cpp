#include <iostream>
#include <vector>

const int MODULO = 100000;

int main() {
  int numCount, numRange, targetSum;
  while (std::cin >> numCount >> numRange >> targetSum && (numCount || numRange || targetSum)) {
    std::vector<std::vector<int>> ways(numCount * numCount + 1, std::vector<int>(targetSum + 1, 0));
    ways[0][0] = 1;

    for (int add = 1; add <= numRange; ++add) {
      for (int currIndex = numCount * numCount; currIndex >= 1; --currIndex) {
        for (int currSum = add; currSum <= targetSum; ++currSum) {
          (ways[currIndex][currSum] += ways[currIndex - 1][currSum - add]) %= MODULO;
        }
      }
    }

    std::cout << ways[numCount * numCount][targetSum] << std::endl;
  }
  return 0;
}
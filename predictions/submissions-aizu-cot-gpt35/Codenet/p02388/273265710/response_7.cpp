#include <iostream>
#include <cmath>

void cubedNum() {
  int inputNum;
  do {
    std::cin >> inputNum;
  } while (inputNum < 0 || inputNum > 100);

  int result = std::pow(inputNum, 3);
  std::cout << result << std::endl;
}

int main() {
  cubedNum();
  return 0;
}
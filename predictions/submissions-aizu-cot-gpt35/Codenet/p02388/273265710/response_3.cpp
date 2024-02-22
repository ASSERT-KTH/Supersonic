#include <iostream>
#include <cmath>

void cubedNum() {
  int inputNum = -1;
  int result = 1;

  do {
    std::cin >> inputNum;
  } while (inputNum < 0 || inputNum > 100);

  result = std::pow(inputNum, 3);

  std::cout << result << '\n';
}

int main() {
  cubedNum();
  return 0;
}
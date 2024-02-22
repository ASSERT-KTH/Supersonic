#include <iostream>

int cubedNum() {
  int inputNum;
  do {
    std::cin >> inputNum;
  } while (inputNum < 0 || inputNum > 100);

  return inputNum * inputNum * inputNum;
}

int main() {
  std::cout << cubedNum() << std::endl;
  return 0;
}
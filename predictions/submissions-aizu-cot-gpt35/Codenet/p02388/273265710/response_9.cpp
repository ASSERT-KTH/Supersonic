#include <iostream>
#include <cmath>

void cubedNum(void) {
  int inputNum = -1;
  int result = 1;
  
  while (inputNum < 0 || inputNum > 100) {
    std::cin >> inputNum;
  }
  
  result = std::pow(inputNum, 3);
  
  std::cout << result << std::endl;
}

int main(void) {
  cubedNum();
  return 0;
}
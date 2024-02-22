#include <iostream>

void cubedNum() {
  int inputNum;
  int result = 1;
  
  do {
    std::cin >> inputNum;
  } while (inputNum < 0 || inputNum > 100);
  
  result = inputNum * inputNum * inputNum;
  
  std::cout << result << std::endl;
}

int main() {
  cubedNum();
  return 0;
}
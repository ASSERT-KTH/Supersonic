#include <iostream>

void cubedNum() {
  int inputNum;
  
  while (true) {
    std::cin >> inputNum;
    if (inputNum >= 0 && inputNum <= 100) {
      break;
    }
  }
  
  int result = inputNum * inputNum * inputNum;
  std::cout << result << std::endl;
}

int main() {
  cubedNum();
  return 0;
}
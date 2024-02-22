#include <iostream>

void cubedNum() {
  int inputNum = -1;
  while (true) {
    std::cout << "Enter a number between 0 and 100: ";
    std::cin >> inputNum;
    if ((0 <= inputNum) && (inputNum <= 100)) {
      break;
    }
    std::cout << "Invalid input. Please try again.\n";
  }
  
  int result = inputNum * inputNum * inputNum;
  
  std::cout << result << std::endl;
}

int main() {
  cubedNum();
  return 0;
}
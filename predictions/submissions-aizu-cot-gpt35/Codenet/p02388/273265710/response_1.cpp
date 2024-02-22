#include <iostream>

void cubedNum() {
  int result = 1;
  int inputNum;
  while (true) {
    std::cin >> inputNum;
    if (inputNum < 0 || inputNum > 100) {
      continue;
    }
    break;
  }
  for (int i = 3; i >= 1; --i) {
    result *= inputNum;
  }
  std::cout << result << std::endl;
}

int main() {
  cubedNum();
  return 0;
}
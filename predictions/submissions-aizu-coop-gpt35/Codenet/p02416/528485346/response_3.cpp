#include <iostream>

const int MAX_LENGTH = 1000;

int main() {
  char* num = new char[MAX_LENGTH + 1];
  while (true) {
    std::cin >> num;
    if (num[0] == '0')
      break;
    int length = strlen(num);
    int sum = 0;
    for (int i = 0; i < length; i++) {
      sum += num[i] - 48;
    }
    std::cout << sum << std::endl;
  }
  delete[] num;
  return 0;
}
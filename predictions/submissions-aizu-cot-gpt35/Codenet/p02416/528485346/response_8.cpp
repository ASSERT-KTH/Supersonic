#include <iostream>

int main() {
  char num[1001];
  while (true) {
    std::cin >> num;
    if (num[0] == '0')
      break;
    int sum = 0;
    int len = std::cin.gcount() - 1;
    for (int i = 0; i < len; i++) {
      sum += num[i] - '0';
    }
    std::cout << sum << std::endl;
  }
  return 0;
}
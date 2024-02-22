#include <iostream>
#include <string>

int main() {
  std::string num;
  while (true) {
    std::cin >> num;
    if (num[0] == '0')
      break;
    int sum = 0;
    int length = num.length();
    for (int i = 0; i < length; i++) {
      sum += static_cast<int>(num[i] - '0');
    }
    std::cout << sum << std::endl;
  }
  return 0;
}
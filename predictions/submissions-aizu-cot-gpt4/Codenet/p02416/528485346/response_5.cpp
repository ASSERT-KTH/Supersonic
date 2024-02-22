#include <iostream>
#include <cstring>

int main() {
  char num[1001];
  while (true) {
    std::cin >> num;
    if (num[0] == '0')
      break;
    int sum = 0;
    int length = std::strlen(num);
    for (int i = 0; i < length; ++i) {
      sum += num[i] - '0';
    }
    std::cout << sum << "\n";
  }
  return 0;
}
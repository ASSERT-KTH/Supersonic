#include <iostream>
#include <cmath>

int main() {
  int input;
  while (std::cin >> input && input) {
    int ans = 0;
    for (int i = 1; i * i * i <= input * input * input; i++) {
      int temp = input * input * input - i * i * i;
      if (temp < ans) {
        break;
      }
      ans = temp;
    }
    std::cout << ans << std::endl;
  }
}
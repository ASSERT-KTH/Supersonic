#include <iostream>
#include <bitset>

int main() {
  std::bitset<31> data;
  int n;
  for (int i = 0; i < 28; i++) {
    std::cin >> n;
    data.set(n);
  }
  for (int i = 1; i <= 30; i++) {
    if (!data[i])
      std::cout << i << '\n';
  }
}
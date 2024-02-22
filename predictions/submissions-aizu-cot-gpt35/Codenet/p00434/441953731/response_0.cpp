#include <iostream>
#include <bitset>
#include <vector>

int main() {
  std::vector<int> data(28);
  for (int i = 0; i < 28; i++) {
    std::cin >> data[i];
  }

  std::bitset<30> presence;
  for (int num : data) {
    presence.set(num - 1);
  }

  for (int i = 0; i < 30; i++) {
    if (!presence[i]) {
      std::cout << i + 1 << std::endl;
    }
  }

  return 0;
}
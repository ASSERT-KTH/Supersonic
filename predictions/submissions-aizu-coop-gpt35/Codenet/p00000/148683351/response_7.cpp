#include <iostream>
#include <string>

int main() {
  const int tableSize = 10;
  const int maxDigits = 2;
  const std::string separator = "   ";

  std::string table[tableSize][tableSize];

  for (int i = 1; i < tableSize; ++i) {
    for (int j = i; j < tableSize; ++j) {
      int value = i * j;
      table[i][j] = std::to_string(value);
      table[j][i] = std::to_string(value);
    }
  }

  for (int i = 1; i < tableSize; ++i) {
    for (int j = 1; j < tableSize; ++j) {
      std::cout << table[i][j];
      std::cout << std::string(maxDigits - table[i][j].length(), ' ');
      std::cout << separator;
    }
    std::cout << std::endl;
  }

  return 0;
}
#include <iostream>

int main(int argc, char* argv[]) {
  int x = std::stoi(argv[1]);
  int result = x * x * x;
  std::cout << result << "\n";
  return 0;
}
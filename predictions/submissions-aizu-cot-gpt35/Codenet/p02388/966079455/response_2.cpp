#include <iostream>
#include <cstdlib>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <x>\n";
    return 1;
  }

  int x = std::atoi(argv[1]);
  int y = x * x * x;

  std::cout << y << "\n";
  return 0;
}
#include <iostream>
#include <cmath>

int main(int argc, char* argv[]) {
  if (argc < 4) {
    std::cout << "Usage: " << argv[0] << " a b c" << std::endl;
    return 1;
  }

  uint32_t a = std::stoi(argv[1]);
  uint32_t b = std::stoi(argv[2]);
  uint32_t c = std::stoi(argv[3]);

  uint32_t t = 0;
  uint32_t sqrt_c = std::sqrt(c);

  for (uint32_t s = a; s <= sqrt_c; ++s) {
    if (c % s == 0) {
      ++t;
    }
  }

  uint32_t remaining = b - sqrt_c;
  if (remaining > 0) {
    t += remaining;
  }

  std::cout << t << std::endl;
  return 0;
}
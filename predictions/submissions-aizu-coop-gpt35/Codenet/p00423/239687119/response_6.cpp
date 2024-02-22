#include <iostream>
#include <vector>

int main() {
  std::vector<int> veca, vecb;
  veca.reserve(1000); // Reserve space for a conservative estimate of iterations
  vecb.reserve(1000); // Reserve space for a conservative estimate of iterations

  int n;
  int a = 0;
  int b = 0;
  int game_a, game_b;
  while (true) {
    std::cin >> n;
    if (n == 0)
      break;
    else {
      for (int i = 0; i < n; ++i) {
        std::cin >> game_a >> game_b;
        a = (game_a + game_b) / 2 + (game_a > game_b ? game_a : 0);
        b = (game_a + game_b) / 2 + (game_a < game_b ? game_b : 0);
      }
      veca.push_back(a);
      vecb.push_back(b);
      a = 0;
      b = 0;
    }
  }
  for (const auto& score : veca) {
    std::cout << score << " ";
  }
  std::cout << std::endl;
  for (const auto& score : vecb) {
    std::cout << score << " ";
  }
  std::cout << std::endl;

  return 0;
}
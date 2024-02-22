#include <iostream>
#include <vector>
int main() {
  int n;
  int a = 0;
  int b = 0;
  int game_a, game_b;
  std::vector<std::pair<int, int>> vec;
  while (1) {
    std::cin >> n;
    if (n == 0)
      break;
    else {
      for (int i = 0; i < n; ++i) {
        std::cin >> game_a >> game_b;
        int sum = game_a + game_b;
        if (game_a >= game_b)
          a += sum;
        else
          b += sum;
      }
      vec.push_back(std::make_pair(a, b));
      a = 0;
      b = 0;
    }
  }
  for (const auto& scores : vec) {
    std::cout << scores.first << " " << scores.second << std::endl;
  }
  return 0;
}
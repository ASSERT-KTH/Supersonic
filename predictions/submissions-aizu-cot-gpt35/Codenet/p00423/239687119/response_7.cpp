#include <iostream>
#include <vector>

int main() {
  int n;
  int a = 0;
  int b = 0;
  std::vector<std::pair<int, int>> results;
  
  while (std::cin >> n && n != 0) {
    for (int i = 0; i < n; ++i) {
      int game_a, game_b;
      std::cin >> game_a >> game_b;
      if (game_a == game_b) {
        a += game_a;
        b += game_b;
      } else if (game_a > game_b) {
        a += game_a + game_b;
      } else {
        b += game_a + game_b;
      }
    }
    results.push_back(std::make_pair(a, b));
    a = 0;
    b = 0;
  }

  for (const auto& result : results) {
    std::cout << result.first << " " << result.second << std::endl;
  }

  return 0;
}
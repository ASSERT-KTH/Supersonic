#include <iostream>
#include <vector>

int main() {
  int n;
  int sum_a = 0;
  int sum_b = 0;
  std::vector<std::pair<int, int>> results;

  while (true) {
    std::cin >> n;
    if (n == 0)
      break;
    else {
      for (int i = 0; i < n; ++i) {
        int game_a, game_b;
        std::cin >> game_a >> game_b;
        sum_a += game_a + game_b;
        sum_b += game_a + game_b;
      }
      results.emplace_back(sum_a, sum_b);
    }
  }

  for (const auto& result : results) {
    std::cout << result.first << " " << result.second << std::endl;
  }

  return 0;
}
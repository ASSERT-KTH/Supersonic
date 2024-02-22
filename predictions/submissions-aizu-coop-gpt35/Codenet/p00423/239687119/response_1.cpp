#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<std::pair<int, int>> scores;
  int sum_a = 0;
  int sum_b = 0;

  while (true) {
    std::cin >> n;
    if (n == 0)
      break;

    for (int i = 0; i < n; ++i) {
      int game_a, game_b;
      std::cin >> game_a >> game_b;
      sum_a += game_a;
      sum_b += game_b;
    }

    scores.emplace_back(sum_a, sum_b);
    sum_a = 0;
    sum_b = 0;
  }

  for (const auto& score : scores) {
    std::cout << score.first << " " << score.second << std::endl;
  }

  return 0;
}
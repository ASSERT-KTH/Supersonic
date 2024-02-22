#include <iostream>
#include <vector>

int main() {
  int n;
  std::vector<std::pair<int, int>> scores;

  while (1) {
    std::cin >> n;
    if (n == 0)
      break;

    int a = 0;
    int b = 0;

    for (int i = 0; i < n; ++i) {
      int game_a, game_b;
      std::cin >> game_a >> game_b;
      
      a += game_a;
      b += game_b;
    }

    scores.push_back(std::make_pair(a, b));
  }

  for (const auto& score : scores) {
    std::cout << score.first << " " << score.second << std::endl;
  }

  return 0;
}
#include <iostream>
#include <vector>

int main() {
  int n;
  int a = 0;
  int b = 0;
  std::vector<int> veca, vecb;

  while (1) {
    std::cin >> n;
    if (n == 0)
      break;
    else {
      // Reset scores for each game
      a = 0;
      b = 0;

      for (int i = 0; i < n; ++i) {
        int game_a, game_b;
        std::cin >> game_a >> game_b;
        if (game_a == game_b) {
          a += game_a;
          b += game_b;
        } else if (game_a > game_b)
          a += game_a + game_b;
        else
          b += game_a + game_b;
      }
      veca.push_back(a);
      vecb.push_back(b);
    }
  }

  // Print the scores
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
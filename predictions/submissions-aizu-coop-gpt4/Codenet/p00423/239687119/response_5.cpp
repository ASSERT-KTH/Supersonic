#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false); // Speed up cin and cout operations
  std::cin.tie(nullptr); // Unbind cin from cout to improve performance

  int n;
  int a = 0;
  int b = 0;
  int game_a, game_b;

  while (1) {
    std::cin >> n;
    if (n == 0)
      break;
    else {
      for (int i = 0; i < n; ++i) {
        std::cin >> game_a >> game_b;
        int sum = game_a + game_b; // Calculate sum once to avoid redundant computation
        if (game_a == game_b) {
          a += sum;
          b += sum;
        } else if (game_a > game_b)
          a += sum;
        else
          b += sum;
      }
      std::cout << a << " " << b << std::endl; // Print results immediately to save memory
      a = 0;
      b = 0;
    }
  }

  return 0;
}
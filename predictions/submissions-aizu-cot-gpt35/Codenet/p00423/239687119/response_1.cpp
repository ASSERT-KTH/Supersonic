#include <iostream>

int main() {
  int n;
  while (true) {
    std::cin >> n;
    if (n == 0)
      break;
    else {
      int a = 0;
      int b = 0;
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
      std::cout << a << " " << b << std::endl;
    }
  }
  return 0;
}
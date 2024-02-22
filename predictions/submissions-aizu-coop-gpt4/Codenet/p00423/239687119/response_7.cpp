#include <iostream>

int main() {
  int n;
  int game_a, game_b;
  while (true) {
    std::cin >> n;
    if (n == 0)
      break;
    else {
      int a = 0, b = 0;
      for (int i = 0; i < n; ++i) {
        std::cin >> game_a >> game_b;
        int sum = game_a + game_b;
        if (game_a == game_b) {
          a += game_a;
          b += game_b;
        } else if (game_a > game_b)
          a += sum;
        else
          b += sum;
      }
      std::cout << a << " " << b << std::endl;
    }
  }
  return 0;
}
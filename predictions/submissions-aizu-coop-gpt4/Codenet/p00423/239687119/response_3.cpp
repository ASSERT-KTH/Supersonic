#include <iostream>
int main() {
  std::ios_base::sync_with_stdio(false); 
  std::cin.tie(NULL); 
  int n;
  int game_a, game_b;
  while (1) {
    std::cin >> n;
    if (n == 0)
      break;
    else {
      int a = 0, b = 0;
      for (int i = 0; i < n; ++i) {
        std::cin >> game_a >> game_b;
        if (game_a == game_b) {
          a += game_a;
          b += game_b;
        } else if (game_a > game_b)
          a += game_a + game_b;
        else
          b += game_a + game_b;
      }
      std::cout << a << " " << b << '\n';
    }
  }
  return 0;
}
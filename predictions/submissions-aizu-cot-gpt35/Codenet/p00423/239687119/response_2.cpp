#include <iostream>

int main() {
  int n;
  int total_a = 0;
  int total_b = 0;
  int game_a, game_b;
  
  while (true) {
    std::cin >> n;
    if (n == 0)
      break;

    for (int i = 0; i < n; ++i) {
      std::cin >> game_a >> game_b;
      if (game_a == game_b) {
        total_a += game_a;
        total_b += game_b;
      } else if (game_a > game_b) {
        total_a += game_a + game_b;
      } else {
        total_b += game_a + game_b;
      }
      std::cout << total_a << " " << total_b << std::endl;
    }
    
    total_a = 0;
    total_b = 0;
  }
  
  return 0;
}
#include <iostream>

int main() {
  int n;
  int total_a = 0;
  int total_b = 0;
  
  while (std::cin >> n && n != 0) {
    for (int i = 0; i < n; ++i) {
      int game_a, game_b;
      scanf("%d %d", &game_a, &game_b);
      
      if (game_a == game_b) {
        total_a += game_a;
        total_b += game_b;
      } else if (game_a > game_b) {
        total_a += game_a + game_b;
      } else {
        total_b += game_a + game_b;
      }
      
      printf("%d %d\n", total_a, total_b);
    }
  }
  
  return 0;
}
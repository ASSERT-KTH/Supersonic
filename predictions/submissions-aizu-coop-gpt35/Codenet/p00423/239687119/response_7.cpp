#include <iostream>

int main() {
  unsigned char a = 0;
  unsigned char b = 0;
  unsigned char game_a, game_b;
  
  while (true) {
    int n;
    std::cin >> n;
    
    if (n == 0)
      break;

    for (int i = 0; i < n; ++i) {
      std::cin >> game_a >> game_b;
      
      if (game_a == game_b) {
        a += game_a;
        b += game_b;
      } else if (game_a > game_b) {
        a += game_a + game_b;
      } else {
        b += game_a + game_b;
      }
    }

    std::cout << static_cast<int>(a) << " " << static_cast<int>(b) << std::endl;

    a = 0;
    b = 0;
  }

  return 0;
}
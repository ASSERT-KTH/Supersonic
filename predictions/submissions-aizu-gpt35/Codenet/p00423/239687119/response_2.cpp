#include <iostream>
#include <vector>

int main() {
  int n;
  while (std::cin >> n && n != 0) {
    int a = 0;
    int b = 0;
    std::vector<int> veca(n), vecb(n);
    for (int i = 0; i < n; ++i) {
      int game_a, game_b;
      std::cin >> game_a >> game_b;
      if (game_a == game_b) {
        a += game_a;
        b += game_b;
      } else if (game_a > game_b) {
        a += game_a + game_b;
      } else {
        b += game_a + game_b;
      }
      veca[i] = a;
      vecb[i] = b;
    }
    for (int i = 0; i < n; ++i) {
      std::cout << veca[i] << " " << vecb[i] << std::endl;
    }
  }
  return 0;
}
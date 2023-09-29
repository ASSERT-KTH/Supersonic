#include <iostream>
#include <vector>
int main() {
  int vec = 0;
  int n;
  int a = 0;
  int b = 0;
  int game_a, game_b;
  std::vector<int> veca, vecb;
  while (std::cin >> n && n != 0) {
    for (int i = 0; i < n; ++i) {
      std::cin >> game_a >> game_b;
      if (game_a == game_b) {
        a += game_a;
        b += game_b;
      } else if (game_a > game_b) {
        a += game_a + game_b;
        b += game_a - game_b;
      } else {
        a += game_a + game_b;
        b += game_b - game_a;
      }
    }
    veca.push_back(a);
    vecb.push_back(b);
    a = 0;
    b = 0;
  }
  for (int i = 0; i < veca.size(); ++i) {
    std::cout << veca[i] << " " << vecb[i] << std::endl;
  }
  return 0;
}
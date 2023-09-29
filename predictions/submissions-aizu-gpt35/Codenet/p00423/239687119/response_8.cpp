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
    veca.push_back(0);
    vecb.push_back(0);
    for (int i = 0; i < n; ++i) {
      std::cin >> game_a >> game_b;
      if (game_a == game_b) {
        veca.back() += game_a;
        vecb.back() += game_b;
      } else if (game_a > game_b) {
        veca.back() += game_a + game_b;
        vecb.back() += game_a - game_b;
      } else {
        vecb.back() += game_a + game_b;
        veca.back() += game_b - game_a;
      }
    }
  }
  for (int i = 0; i < veca.size(); ++i) {
    std::cout << veca[i] << " " << vecb[i] << std::endl;
  }
  return 0;
}
#include <iostream>
#include <vector>

int main() {
  int n;
  int a = 0;
  int b = 0;
  std::vector<int> veca, vecb;

  while (std::cin >> n && n != 0) {
    veca.reserve(n);
    vecb.reserve(n);

    for (int i = 0; i < n; ++i) {
      int game_a, game_b;
      std::cin >> game_a >> game_b;

      int sum = game_a + game_b;
      a += sum;
      b += sum;

      if (game_a < game_b) {
        a -= sum;
      } else if (game_a > game_b) {
        b -= sum;
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
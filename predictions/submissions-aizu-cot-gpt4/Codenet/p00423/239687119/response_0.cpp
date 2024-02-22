#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(NULL);

  int n;
  int a = 0;
  int b = 0;
  int game_a, game_b;
  std::vector<int> veca, vecb;
  veca.reserve(1000); // Assume 1000 as a reasonable reserve size.
  vecb.reserve(1000); // Assume 1000 as a reasonable reserve size.

  while (1) {
    std::cin >> n;
    if (n == 0)
      break;
    else {
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
      veca.emplace_back(a);
      vecb.emplace_back(b);
      a = 0;
      b = 0;
    }
  }
  for (int i = 0; i < veca.size(); ++i) {
    std::cout << veca[i] << " " << vecb[i] << '\n';
  }
  return 0;
}
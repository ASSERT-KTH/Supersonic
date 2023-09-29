#include <iostream>
#include <vector>

int main() {
  std::ios_base::sync_with_stdio(false); // Faster I/O
  std::cin.tie(NULL); // Untie cin and cout

  std::vector<int> veca, vecb;
  int n, a = 0, b = 0, game_a, game_b;

  while (std::cin >> n && n != 0) {
    while (n--) {
      std::cin >> game_a >> game_b;
      if (game_a >= game_b)
        a += game_a + game_b;
      else
        b += game_a + game_b;
    }
    veca.push_back(a);
    vecb.push_back(b);
    a = b = 0;
  }

  for (size_t i = 0, size = veca.size(); i < size; ++i) {
    std::cout << veca[i] << ' ' << vecb[i] << '\n';
  }

  return 0;
}
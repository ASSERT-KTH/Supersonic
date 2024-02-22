#include <iostream>
#include <vector>
int main() {
  int n;
  std::vector<std::pair<int, int>> vec;
  vec.reserve(100);  // Reserve memory upfront for efficiency
  while (std::cin >> n && n != 0) {
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
      int game_a, game_b;
      std::cin >> game_a >> game_b;
      if (game_a == game_b) {
        a += game_a;
        b += game_b;
      } else if (game_a > game_b)
        a += game_a + game_b;
      else
        b += game_a + game_b;
    }
    vec.push_back({a, b});
  }
  int size = vec.size();
  for (int i = 0; i < size; ++i) {
    std::cout << vec[i].first << " " << vec[i].second << std::endl;
  }
  return 0;
}
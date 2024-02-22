#include <iostream>
#include <vector>

struct Result {
  int a;
  int b;
};

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(NULL);

  int n;
  int game_a, game_b;
  std::vector<Result> results;
  results.reserve(100);  // Assume a maximum of 100 results

  while (1) {
    std::cin >> n;
    if (n == 0)
      break;

    Result result = {0, 0};

    for (int i = 0; i < n; ++i) {
      std::cin >> game_a >> game_b;
      if (game_a >= game_b)
        result.a += game_a + game_b;
      else
        result.b += game_a + game_b;
    }

    results.push_back(result);
  }

  for (const auto& result : results) {
    std::cout << result.a << " " << result.b << '\n';
  }

  return 0;
}
#include <iostream>
#include <vector>

int main() {
  int n;
  int a = 0;
  int b = 0;
  int game_a, game_b;
  const int MAX_SEQUENCES = 1000; // Adjust the maximum number of sequences if needed
  int veca[MAX_SEQUENCES];
  int vecb[MAX_SEQUENCES];
  int vecSize = 0;

  for (int i = 0; i < MAX_SEQUENCES; ++i) {
    std::cin >> n;
    if (n == 0)
      break;

    for (int j = 0; j < n; ++j) {
      std::cin >> game_a >> game_b;
      if (game_a == game_b) {
        a += game_a;
        b += game_b;
      } else if (game_a > game_b)
        a += game_a + game_b;
      else
        b += game_a + game_b;
    }

    veca[vecSize] = a;
    vecb[vecSize] = b;
    vecSize++;

    a = 0;
    b = 0;
  }

  for (int i = 0; i < vecSize; ++i) {
    std::cout << veca[i] << " " << vecb[i] << std::endl;
  }

  return 0;
}
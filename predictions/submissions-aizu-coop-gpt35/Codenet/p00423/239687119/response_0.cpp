#include <iostream>

const int MAX_GAMES = 1000; // Maximum number of games

int main() {
  int n;
  int a = 0;
  int b = 0;
  int game_a, game_b;
  int veca[MAX_GAMES]; // Array to store cumulative scores of player A
  int vecb[MAX_GAMES]; // Array to store cumulative scores of player B
  int numGames = 0; // Number of games played

  while (true) {
    std::cin >> n;
    if (n == 0)
      break;

    for (int i = 0; i < n; ++i) {
      std::cin >> game_a >> game_b;
      int sum = game_a + game_b;
      if (game_a == game_b) {
        a += sum;
        b += sum;
      } else if (game_a > game_b) {
        a += sum;
      } else {
        b += sum;
      }
    }

    veca[numGames] = a;
    vecb[numGames] = b;
    a = 0;
    b = 0;
    numGames++;
  }

  for (int i = 0; i < numGames; ++i) {
    std::cout << veca[i] << " " << vecb[i] << std::endl;
  }

  return 0;
}
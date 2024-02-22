#include <iostream>

int main() {
  int stone[50] = {0};
  int n, p;

  while (true) {
    std::cin >> n >> p;
    if (n == 0 && p == 0) {
      return 0;
    }

    int bowl = p;
    int currentPlayer = 0;

    while (true) {
      if (bowl == 0) {
        bowl += stone[currentPlayer];
        stone[currentPlayer] = 0;
      } else {
        stone[currentPlayer]++;
        bowl--;

        if (stone[currentPlayer] == p) {
          std::cout << currentPlayer << '\n';
          break;
        }
      }

      currentPlayer = (currentPlayer + 1) % n;
    }
  }
}
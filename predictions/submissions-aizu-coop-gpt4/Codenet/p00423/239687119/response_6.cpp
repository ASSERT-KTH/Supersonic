#include <iostream>

int main() {
  int numGames;
  int scoreA = 0, scoreB = 0;
  int gameScoreA, gameScoreB;

  while (1) {
    std::cin >> numGames;
    if (numGames == 0)
      break;
    else {
      for (int i = 0; i < numGames; ++i) {
        std::cin >> gameScoreA >> gameScoreB;
        scoreA += (gameScoreA >= gameScoreB) ? gameScoreA + gameScoreB : gameScoreA;
        scoreB += (gameScoreB > gameScoreA) ? gameScoreA + gameScoreB : gameScoreB;
      }
      std::cout << scoreA << " " << scoreB << std::endl;
      scoreA = 0;
      scoreB = 0;
    }
  }
  return 0;
}
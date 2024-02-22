#include <iostream>
#include <vector>
#include <array>

const int MAX_T = 3000;

int main() {
  int M, start, goal;
  std::array<int, 6> dice;
  std::cin >> M;
  for (int& d : dice) {
    std::cin >> d;
  }
  std::cin >> start >> goal;
  start--, goal--;

  std::vector<int> N(M);
  for (int& n : N) {
    std::cin >> n;
  }

  std::vector<int> path(M, 2 * MAX_T);
  std::vector<bool> visit(M, false);

  auto makePath = [&](int from) -> int* {
    visit[from] = true;
    int bestPath = MAX_T;
    if (from == goal) {
      bestPath = 0;
    } else {
      for (int r = 0; r < 6; r++) {
        int moveTo = from + dice[r];
        if (moveTo >= 0 && moveTo < M) {
          int position = moveTo + N[moveTo];
          if (!visit[position]) {
            makePath(position);
          }
          bestPath = std::min(bestPath, path[position] + 1);
        }
        moveTo = from - dice[r];
        if (moveTo >= 0 && moveTo < M) {
          int position = moveTo + N[moveTo];
          if (!visit[position]) {
            makePath(position);
          }
          bestPath = std::min(bestPath, path[position] + 1);
        }
      }
    }
    path[from] = bestPath;
    return &path[from];
  };

  int* pathPtr = makePath(start);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal) {
      break;
    }
    int r;
    std::cin >> r;
    int d = dice[r - 1];
    auto tryMove = [&](int moveTo, int pathBefore, int& position) -> bool {
      if (moveTo >= 0 && moveTo < M) {
        if (pathBefore > path[moveTo + N[moveTo]]) {
          position = moveTo + N[moveTo];
          std::cout << ((position > goal) ? -1 : ((position < goal) ? 1 : 0)) << std::endl;
          return true;
        }
      }
      return false;
    };
    if (!tryMove(position + d, path[position], position)) {
      tryMove(position - d, path[position], position);
    }
  }

  return 0;
}
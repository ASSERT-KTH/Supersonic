#include <iostream>

const int MAX_T = 3000;
const int MAX_M = 300;

int M, start, goal, dice[6], *N;

bool isPositionValid(int p) {
  return 0 <= p && p < M;
}

void MakePath(int* path, int from) {
  static bool visit[MAX_M] = {};

  if (path == nullptr) {
    for (int m = 0; m < M; m++)
      path[m] = MAX_T + 1;
  }

  visit[from] = true;
  int bestpath = MAX_T;

  if (from == goal)
    bestpath = 0;
  else {
    for (int r = 0; r < 6; r++) {
      int moveto = from + dice[r];
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        if (!visit[position])
          MakePath(path, position);
        bestpath = std::min(bestpath, path[position] + 1);
      }

      moveto = from - dice[r];
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        if (!visit[position])
          MakePath(path, position);
        bestpath = std::min(bestpath, path[position] + 1);
      }
    }
  }

  path[from] = bestpath;
}

int main() {
  std::cin >> M;
  for (int r = 0; r < 6; r++)
    std::cin >> dice[r];
  std::cin >> start >> goal;
  start--, goal--;
  N = new int[M];
  for (int m = 0; m < M; m++)
    std::cin >> N[m];

  int path[MAX_M];
  MakePath(path, start);

  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;

    int r;
    std::cin >> r;
    int d = dice[r - 1];

    int moveto = position + d;
    if (isPositionValid(moveto) && path[position] > path[moveto + N[moveto]])
      position = moveto + N[moveto];

    moveto = position - d;
    if (isPositionValid(moveto) && path[position] > path[moveto + N[moveto]])
      position = moveto + N[moveto];

    std::cout << (position == goal ? 0 : (position > goal ? -1 : 1)) << '\n';
  }

  delete[] N;
  return 0;
}
#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], *N;
bool isPositionValid(int p) { return 0 <= p && p < M; }
int *MakePath(int *path, int from, bool *visit) {
  static auto checkPath = [&path](int moveto, bool *visit) -> int {
    if (!isPositionValid(moveto))
      return 2 * MAX_T;
    else {
      int position = moveto + N[moveto];
      if (!visit[position])
        MakePath(path, position, visit);
      return path[position] + 1;
    }
  };
  if (path == NULL) {
    path = new int[M];
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
          MakePath(path, position, visit);
        bestpath = min(bestpath, path[position] + 1);
      }

      moveto = from - dice[r];
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        if (!visit[position])
          MakePath(path, position, visit);
        bestpath = min(bestpath, path[position] + 1);
      }
    }
  }
  path[from] = bestpath;
  return path;
}
int main() {
  cin >> M;
  for (int r = 0; r < 6; r++)
    cin >> dice[r];
  cin >> start >> goal;
  start--, goal--;
  N = new int[M];
  for (int m = 0; m < M; m++)
    cin >> N[m];
  bool *visit = new bool[MAX_M]{};
  int path[MAX_M];
  MakePath(path, start, visit);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int moveto = position + d;
    int output;
    if (isPositionValid(moveto) && path[position] > path[moveto + N[moveto]]) {
      position = moveto + N[moveto];
      output = 1;
    } else {
      moveto = position - d;
      if (isPositionValid(moveto) && path[position] > path[moveto + N[moveto]]) {
        position = moveto + N[moveto];
        output = -1;
      } else {
        output = 0;
      }
    }
    cout << output << endl;
  }
  delete[] N;
  delete[] visit;
  return 0;
}
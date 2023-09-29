#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], *N;
bool isPositionValid(int p) { return 0 <= p && p < M; }
int *MakePath(int *path, int from) {
  static bool visit[MAX_M] = {};
  static auto checkPath = [&path](int moveto) -> int {
    if (!isPositionValid(moveto))
      return 2 * MAX_T;
    else {
      int position = moveto + N[moveto];
      if (!visit[position])
        MakePath(path, position);
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
    for (int d : dice) {
      bestpath = min(bestpath, checkPath(from + d));
      bestpath = min(bestpath, checkPath(from - d));
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
  int *path = MakePath(NULL, start);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    static auto tryMove = [&path](int moveto, int &position) -> bool {
      if (isPositionValid(moveto)) {
        int new_position = moveto + N[moveto];
        if (path[position] > path[new_position]) {
          position = new_position;
          return true;
        }
      }
      return false;
    };
    int output;
    if (tryMove(position + d, position))
      output = 1;
    else if (tryMove(position - d, position))
      output = -1;
    else
      output = 0;
    cout << output << endl;
  }
  delete[] N;
  delete[] path;
  return 0;
}

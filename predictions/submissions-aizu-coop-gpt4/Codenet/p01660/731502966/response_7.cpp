#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], N[MAX_M], path[MAX_M];
bool isPositionValid(int p) { return 0 <= p && p < M; }
inline int checkPath(int moveto) {
  if (!isPositionValid(moveto))
    return 2 * MAX_T;
  else {
    int position = moveto + N[moveto];
    if (path[position] == MAX_T + 1)
      MakePath(position);
    return path[position] + 1;
  }
}
void MakePath(int from) {
  static bool visit[MAX_M] = {};
  visit[from] = true;
  int bestpath = MAX_T;
  if (from == goal)
    bestpath = 0;
  else {
    for (int r = 0; r < 6; r++) {
      bestpath = min(bestpath, checkPath(from + dice[r]));
      bestpath = min(bestpath, checkPath(from - dice[r]));
    }
  }
  path[from] = bestpath;
}
int main() {
  cin >> M;
  for (int r = 0; r < 6; r++)
    cin >> dice[r];
  cin >> start >> goal;
  start--, goal--;
  for (int m = 0; m < M; m++)
    cin >> N[m];
  for (int m = 0; m < M; m++)
    path[m] = MAX_T + 1;
  MakePath(start);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int output;
    if (checkMove(position + d, path[position], position))
      output = 1;
    else if (checkMove(position - d, path[position], position))
      output = -1;
    else
      output = 0;
    cout << output << endl;
  }
  return 0;
}
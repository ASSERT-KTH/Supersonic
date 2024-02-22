#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], N[MAX_M], path[MAX_M];
bool isPositionValid(int p) { return 0 <= p && p < M; }
int *MakePath(int from) {
  static bool visit[MAX_M] = {};
  static auto checkPath = [](int moveto) -> int {
    if (!visit[moveto + N[moveto]])
      MakePath(moveto);
    return path[moveto] + 1;
  };
  visit[from] = true;
  int bestpath = MAX_T;
  if (from == goal)
    bestpath = 0;
  else {
    for (int r = 0; r < 6; r++) {
      if (isPositionValid(from + dice[r]))
        bestpath = min(bestpath, checkPath(from + dice[r]));
      if (isPositionValid(from - dice[r]))
        bestpath = min(bestpath, checkPath(from - dice[r]));
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
  for (int m = 0; m < M; m++)
    cin >> N[m];
  MakePath(start);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int output;
    if (isPositionValid(position + d) && path[position] > path[position + d + N[position + d]]) {
      position += d + N[position];
      output = 1;
    }
    else if (isPositionValid(position - d) && path[position] > path[position - d + N[position - d]]) {
      position -= d + N[position];
      output = -1;
    }
    else
      output = 0;
    cout << output << endl;
  }
  return 0;
}
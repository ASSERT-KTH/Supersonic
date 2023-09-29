#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_T = 3000;

vector<int> dice(6), N;
int M, start, goal;

bool isPositionValid(int p) { 
    return 0 <= p && p < M; 
}

vector<int> MakePath(vector<int> &path, int from, vector<bool> &visit) {
  auto checkPath = [&](int moveto) -> int {
    if (!isPositionValid(moveto))
      return 2 * MAX_T;
    else {
      int position = moveto + N[moveto];
      if (!visit[position])
        MakePath(path, position, visit);
      return path[position] + 1;
    }
  };
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
  return path;
}

int main() {
  cin >> M;
  for (int r = 0; r < 6; r++)
    cin >> dice[r];
  cin >> start >> goal;
  start--, goal--;

  N.resize(M);
  for (int m = 0; m < M; m++)
    cin >> N[m];

  vector<int> path(M, MAX_T + 1);
  vector<bool> visit(M, false);

  MakePath(path, start, visit);

  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];

    auto tryMove = [&](int moveto, int path_before) -> bool {
      if (isPositionValid(moveto)) {
        if (path_before > path[moveto + N[moveto]]) {
          position = moveto + N[moveto];
          return true;
        }
      }
      return false;
    };
    int output;
    if (tryMove(position + d, path[position]))
      output = 1;
    else if (tryMove(position - d, path[position]))
      output = -1;
    else
      output = 0;
    cout << output << endl;
  }
  return 0;
}
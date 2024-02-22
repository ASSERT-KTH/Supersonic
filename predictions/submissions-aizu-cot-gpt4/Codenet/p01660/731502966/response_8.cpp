#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6];
bool isPositionValid(int p) { return 0 <= p && p < M; }

vector<int> MakePath(vector<int>& path, vector<int>& N, int from) {
  vector<bool> visit(M, false);
  
  // Lambda function moved out of MakePath to avoid recreating it every time
  auto checkPath = [&path, &N, &visit](int moveto) -> int {
    if (!isPositionValid(moveto))
      return 2 * MAX_T;
    else {
      int position = moveto + N[moveto];
      if (!visit[position])
        MakePath(path, N, position);
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
  
  // Use vector instead of dynamically allocated array for N
  vector<int> N(M, 0);
  for (int m = 0; m < M; m++)
    cin >> N[m];
  vector<int> path(M, MAX_T + 1);
  path = MakePath(path, N, start);
  int position = start;
  
  // Lambda function moved out of main to avoid recreating it every time
  auto tryMove = [&path, &N](int moveto, int path_before, int &position) -> bool {
    if (isPositionValid(moveto)) {
      if (path_before > path[moveto + N[moveto]]) {
        position = moveto + N[moveto];
        return true;
      }
    }
    return false;
  };

  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int output;
    if (tryMove(position + d, path[position], position))
      output = 1;
    else if (tryMove(position - d, path[position], position))
      output = -1;
    else
      output = 0;
    cout << output << endl;
  }
  return 0;
}
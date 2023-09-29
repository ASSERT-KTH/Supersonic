#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6];
vector<int> N(MAX_M, 0);
vector<int> path(MAX_M, MAX_T + 1);
vector<bool> visit(MAX_M, false);

bool isPositionValid(int p) { return 0 <= p && p < M; }

int makePath(int from) {
  visit[from] = true;
  int bestpath = MAX_T;
  if (from == goal)
    bestpath = 0;
  else {
    for (int r = 0; r < 6; r++) {
      int moveTo = from + dice[r];
      if (isPositionValid(moveTo) && !visit[moveTo]) {
        bestpath = min(bestpath, makePath(moveTo));
      }
      moveTo = from - dice[r];
      if (isPositionValid(moveTo) && !visit[moveTo]) {
        bestpath = min(bestpath, makePath(moveTo));
      }
    }
  }
  path[from] = bestpath + 1;
  return path[from];
}

int main() {
  cin >> M;
  for (int r = 0; r < 6; r++)
    cin >> dice[r];
  cin >> start >> goal;
  start--, goal--;
  for (int m = 0; m < M; m++)
    cin >> N[m];
  
  makePath(start);
  int position = start;
  
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int moveTo = position + d;
    if (isPositionValid(moveTo) && path[position] > path[moveTo]) {
      position = moveTo;
      cout << 1 << '\n';
      continue;
    }
    moveTo = position - d;
    if (isPositionValid(moveTo) && path[position] > path[moveTo]) {
      position = moveTo;
      cout << -1 << '\n';
      continue;
    }
    cout << 0 << '\n';
  }
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6];
vector<int> N;
bool isPositionValid(int p) { return 0 <= p && p < M; }

int checkPath(vector<int> &path, int moveto, int visitedPos) {
  if (!isPositionValid(moveto))
    return 2 * MAX_T;
  else {
    int position = moveto + N[moveto];
    if (position != visitedPos)
      path = MakePath(path, position);
    return path[position] + 1;
  }
}

bool tryMove(vector<int> &path, int moveto, int &position) {
  if (isPositionValid(moveto)) {
    if (path[position] > path[moveto + N[moveto]]) {
      position = moveto + N[moveto];
      return true;
    }
  }
  return false;
}

vector<int> MakePath(vector<int> path, int from) {
  int visitedPos = from;
  path.resize(M, MAX_T + 1);
  int bestpath = (from == goal) ? 0 : MAX_T;
  if (from != goal) {
    for (int r = 0; r < 6; r++) {
      bestpath = min(bestpath, checkPath(path, from + dice[r], visitedPos));
      bestpath = min(bestpath, checkPath(path, from - dice[r], visitedPos));
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
  vector<int> path = MakePath({}, start);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int output;
    if (tryMove(path, position + d, position))
      output = 1;
    else if (tryMove(path, position - d, position))
      output = -1;
    else
      output = 0;
    cout << output << endl;
  }
  return 0;
}
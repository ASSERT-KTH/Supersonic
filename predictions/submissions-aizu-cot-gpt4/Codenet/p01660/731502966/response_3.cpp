#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6];
vector<int> N;
bool isPositionValid(int p) { return 0 <= p && p < M; }

vector<int> MakePath(vector<int> path, int from) {
  static bool visit[MAX_M] = {};
  static int cache[MAX_M] = {2 * MAX_T};
  static auto checkPath = [&path](int moveto) -> int {
    if (!isPositionValid(moveto))
      return 2 * MAX_T;

    if (cache[moveto] != 2 * MAX_T)
      return cache[moveto];
    else {
      int position = moveto + N[moveto];
      if (!visit[position])
        MakePath(path, position);
      return cache[moveto] = path[position] + 1;
    }
  };

  if (path.empty()) {
    path.resize(M, MAX_T + 1);
  }
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
  vector<int> path = MakePath({}, start);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    static auto tryMove = [&path](int moveto, int path_before) -> int {
      if (isPositionValid(moveto)) {
        if (path_before > path[moveto + N[moveto]]) {
          return moveto + N[moveto];
        }
      }
      return -1;
    };
    int newPosition = tryMove(position + d, path[position]);
    int output;
    if (newPosition != -1) {
      position = newPosition;
      output = 1;
    } else if ((newPosition = tryMove(position - d, path[position])) != -1) {
      position = newPosition;
      output = -1;
    } else {
      output = 0;
    }
    cout << output << endl;
  }
  return 0;
}
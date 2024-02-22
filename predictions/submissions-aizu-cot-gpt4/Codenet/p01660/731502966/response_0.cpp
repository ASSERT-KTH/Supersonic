#include <iostream>
#include <array>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;

array<int, 6> dice;
array<int, MAX_M> N, path;
int M, start, goal;

bool isPositionValid(int p) { return 0 <= p && p < M; }

int* MakePath(int from) {
  static bool visit[MAX_M] = {};
  static auto checkPath = [](int moveto) -> int {
    if (!isPositionValid(moveto))
      return 2 * MAX_T;
    else {
      int position = moveto + N[moveto];
      if (!visit[position])
        MakePath(position);
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
  return path.data();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

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
    static auto tryMove = [](int moveto, int path_before,
                             int &position) -> bool {
      if (path_before > path[moveto + N[moveto]]) {
        position = moveto + N[moveto];
        return true;
      }
      return false;
    };
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
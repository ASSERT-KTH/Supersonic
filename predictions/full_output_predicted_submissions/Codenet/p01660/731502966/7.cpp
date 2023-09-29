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
    for (int r = 0; r < 6; r++) {
      bestpath = min(bestpath, checkPath(from + dice[r]));
      bestpath = min(bestpath, checkPath(from - dice[r]));
    }
  }
  path[from] = bestpath;
  return path;
}
int main() {
  scanf("%d", &M);
  for (int r = 0; r < 6; r++)
    scanf("%d", & dice[r]);
  scanf("%d%d", &start, &goal);
  start--, goal--;
  N = new int[M];
  for (int m = 0; m < M; m++)
    scanf("%d", &N[m]);
  int *path = MakePath
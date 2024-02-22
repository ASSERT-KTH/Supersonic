#include <cstdio>
#define MAX_T 3000
#define MAX_M 300

int M, start, goal, dice[6], *N, path[MAX_M];
bool isPositionValid(int p) { return 0 <= p && p < M; }
int *MakePath(int from) {
  static bool visit[MAX_M] = {};
  static auto checkPath = [from](int moveto) -> int {
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
      int path_result_plus = checkPath(from + dice[r]);
      int path_result_minus = checkPath(from - dice[r]);
      bestpath = min(bestpath, path_result_plus);
      bestpath = min(bestpath, path_result_minus);
    }
  }
  path[from] = bestpath;
  return path;
}
int main() {
  scanf("%d", &M);
  for (int r = 0; r < 6; r++)
    scanf("%d", &dice[r]);
  scanf("%d%d", &start, &goal);
  start--, goal--;
  N = new int[M];
  for (int m = 0; m < M; m++)
    scanf("%d", &N[m]);
  int *path = MakePath(start);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    scanf("%d", &r);
    int d = dice[r - 1];
    static auto tryMove = [&path](int moveto, int path_before,
                                  int &position) -> bool {
      if (isPositionValid(moveto)) {
        if (path_before > path[moveto + N[moveto]]) {
          position = moveto + N[moveto];
          return true;
        }
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
    printf("%d\n", output);
  }
  delete[] N;
  return 0;
}
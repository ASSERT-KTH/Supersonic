#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], *N;
bool isPositionValid(int p) { return 0 <= p && p < M; }
void MakePath(int *path, int from) {
  bool visit[MAX_M] = {};
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
      int moveto = from + dice[r];
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        if (!visit[position])
          MakePath(path, position);
        bestpath = min(bestpath, path[position] + 1);
      }
      moveto = from - dice[r];
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        if (!visit[position])
          MakePath(path, position);
        bestpath = min(bestpath, path[position] + 1);
      }
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
  N = new int[M];
  for (int m = 0; m < M; m++)
    cin >> N[m];
  int path[MAX_M];
  for (int m = 0; m < M; m++)
    path[m] = MAX_T + 1;
  MakePath(path, start);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    if (isPositionValid(position + d)) {
      int moveto = position + d;
      int path_before = path[position];
      if (path_before > path[moveto + N[moveto]]) {
        position = moveto + N[moveto];
        cout << 1 << endl;
        continue;
      }
    }
    if (isPositionValid(position - d)) {
      int moveto = position - d;
      int path_before = path[position];
      if (path_before > path[moveto + N[moveto]]) {
        position = moveto + N[moveto];
        cout << -1 << endl;
        continue;
      }
    }
    cout << 0 << endl;
  }
  delete[] N;
  return 0;
}
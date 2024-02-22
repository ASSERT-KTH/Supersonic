#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], *N;
bool isPositionValid(int p) { return 0 <= p && p < M; }

int *MakePath() {
  int *path = new int[M];
  for (int m = 0; m < M; m++)
    path[m] = MAX_T + 1;
  path[goal] = 0;
  for (int m = goal - 1; m >= 0; m--) {
    for (int r = 0; r < 6; r++) {
      int moveto = min(max(m + dice[r], 0), M - 1);
      path[m] = min(path[m], path[moveto + N[moveto]] + 1);
      moveto = max(min(m - dice[r], M - 1), 0);
      path[m] = min(path[m], path[moveto + N[moveto]] + 1);
    }
  }
  return path;
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
  int *path = MakePath();
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int moveto = min(max(position + d, 0), M - 1);
    int output;
    if (path[position] > path[moveto + N[moveto]]) {
      position = moveto + N[moveto];
      output = 1;
    } else {
      moveto = max(min(position - d, M - 1), 0);
      if (path[position] > path[moveto + N[moveto]]) {
        position = moveto + N[moveto];
        output = -1;
      } else
        output = 0;
    }
    cout << output << endl;
  }
  delete[] N;
  delete[] path;
  return 0;
}
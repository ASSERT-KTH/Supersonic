#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], N[MAX_M], path[MAX_M];

bool isPositionValid(int p) {
  return 0 <= p && p < M;
}

void MakePath() {
  for (int m = 0; m < M; m++) {
    path[m] = MAX_T + 1;
  }
  path[goal] = 0;

  for (int i = 0; i < M; i++) {
    for (int r = 0; r < 6; r++) {
      int moveto = i + dice[r];
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        path[i] = min(path[i], path[position] + 1);
      }
      moveto = i - dice[r];
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        path[i] = min(path[i], path[position] + 1);
      }
    }
  }
}

int main() {
  cin >> M;
  for (int r = 0; r < 6; r++) {
    cin >> dice[r];
  }
  cin >> start >> goal;
  start--, goal--;
  for (int m = 0; m < M; m++) {
    cin >> N[m];
  }
  MakePath();
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal) {
      break;
    }
    int r;
    cin >> r;
    int d = dice[r - 1];
    int moveto = position + d;
    if (isPositionValid(moveto) && path[position] > path[moveto + N[moveto]]) {
      position = moveto + N[moveto];
      cout << 1 << endl;
    } else {
      moveto = position - d;
      if (isPositionValid(moveto) && path[position] > path[moveto + N[moveto]]) {
        position = moveto + N[moveto];
        cout << -1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
  return 0;
}
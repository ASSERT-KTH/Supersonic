#include <iostream>
using namespace std;

const int MAX_T = 3000, MAX_M = 300;

bool isPositionValid(int p, int M) {
  return 0 <= p && p < M;
}

void MakePath(int *path, int M, int start, int goal, int *dice, int *N) {
  if (path == nullptr) {
    path = new int[M];
    for (int m = 0; m < M; m++)
      path[m] = MAX_T + 1;
  }

  path[start] = 0;

  for (int t = 0; t < MAX_T; t++) {
    int bestpath = MAX_T;
    int position = -1;

    for (int from = 0; from < M; from++) {
      if (path[from] == t) {
        if (from == goal) {
          bestpath = 0;
          break;
        }

        for (int r = 0; r < 6; r++) {
          int moveto = from + dice[r];
          int newPosition = moveto + N[moveto];

          if (isPositionValid(newPosition, M) && path[newPosition] > t + 1) {
            path[newPosition] = t + 1;
            if (bestpath > t + 1) {
              bestpath = t + 1;
              position = newPosition;
            }
          }
        }
      }
    }

    if (bestpath == MAX_T)
      break;
      
    if (position == goal)
      break;
  }

  delete[] path;
}

int main() {
  int M;
  cin >> M;

  int dice[6];
  for (int r = 0; r < 6; r++)
    cin >> dice[r];

  int start, goal;
  cin >> start >> goal;
  start--, goal--;

  int *N = new int[M];
  for (int m = 0; m < M; m++)
    cin >> N[m];

  int *path = new int[M];
  MakePath(path, M, start, goal, dice, N);

  int position = start;

  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;

    int r;
    cin >> r;
    int d = dice[r - 1];
    int newPosition = position + d;

    if (isPositionValid(newPosition, M) && path[newPosition] > path[position]) {
      position = newPosition;
      cout << 1 << endl;
    } else {
      newPosition = position - d;
      if (isPositionValid(newPosition, M) && path[newPosition] > path[position]) {
        position = newPosition;
        cout << -1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }

  delete[] N;
  delete[] path;

  return 0;
}
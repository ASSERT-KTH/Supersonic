#include <iostream>
using namespace std;

const int MAX_M = 300;

bool isPositionValid(int p, int M) {
  return 0 <= p && p < M;
}

void MakePath(int *path, int M, int *N, int start, int goal, int *dice) {
  bool visit[MAX_M] = {};
  int position = start;
  path[start] = 0;

  for (int t = 0; t < MAX_M; t++) {
    if (position == goal)
      break;

    int bestpath = MAX_M + 1;
    int moveto = position + dice[0];

    if (isPositionValid(moveto, M)) {
      int next_position = moveto + N[moveto];
      if (!visit[next_position]) {
        MakePath(path, M, N, next_position, goal, dice);
      }
      bestpath = min(bestpath, path[next_position] + 1);
    }

    moveto = position - dice[0];
    if (isPositionValid(moveto, M)) {
      int next_position = moveto + N[moveto];
      if (!visit[next_position]) {
        MakePath(path, M, N, next_position, goal, dice);
      }
      bestpath = min(bestpath, path[next_position] + 1);
    }

    for (int r = 1; r < 6; r++) {
      moveto = position + dice[r];
      if (isPositionValid(moveto, M)) {
        bestpath = min(bestpath, path[moveto + N[moveto]] + 1);
      }

      moveto = position - dice[r];
      if (isPositionValid(moveto, M)) {
        bestpath = min(bestpath, path[moveto + N[moveto]] + 1);
      }
    }

    visit[position] = true;
    path[position] = bestpath;

    int r;
    cin >> r;
    int d = dice[r - 1];

    int moveto = position + d;
    if (isPositionValid(moveto, M) && path[position] > path[moveto + N[moveto]]) {
      position = moveto + N[moveto];
      cout << 1 << endl;
    } else {
      moveto = position - d;
      if (isPositionValid(moveto, M) && path[position] > path[moveto + N[moveto]]) {
        position = moveto + N[moveto];
        cout << -1 << endl;
      } else {
        cout << 0 << endl;
      }
    }
  }
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
  for (int m = 0; m < M; m++)
    path[m] = MAX_M + 1;

  MakePath(path, M, N, start, goal, dice);

  delete[] N;
  delete[] path;

  return 0;
}
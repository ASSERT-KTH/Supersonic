#include <iostream>
using namespace std;

const int MAX_T = 3000;
const int MAX_M = 300;

int M, start, goal, dice[6], *N;
int path[MAX_M] = {};

bool inline isPositionValid(int p) { return 0 <= p && p < M; }

void MakePath(int &position, int from) {
  static bool visit[MAX_M] = {};

  if (!visit[from]) {
    visit[from] = true;

    int bestpath = MAX_T;
    if (from == goal) {
      bestpath = 0;
    } else {
      for (int r = 0; r < 6; r++) {
        int moveto = from + dice[r];
        if (isPositionValid(moveto)) {
          int position = moveto + N[moveto];
          if (!visit[position]) {
            MakePath(position, position);
          }
          bestpath = min(bestpath, path[position] + 1);
        }

        moveto = from - dice[r];
        if (isPositionValid(moveto)) {
          int position = moveto + N[moveto];
          if (!visit[position]) {
            MakePath(position, position);
          }
          bestpath = min(bestpath, path[position] + 1);
        }
      }
    }
    path[from] = bestpath;
  }

  position = from;
}

int main() {
  cin >> M;
  for (int r = 0; r < 6; r++) {
    cin >> dice[r];
  }
  cin >> start >> goal;
  start--, goal--;

  N = new int[M];
  for (int m = 0; m < M; m++) {
    cin >> N[m];
  }

  int position = start;
  MakePath(position, start);

  for (int t = 0; t < MAX_T; t++) {
    if (position == goal) {
      break;
    }
    int r;
    cin >> r;
    int d = dice[r - 1];
    int output;
    if (isPositionValid(position + d) && path[position] > path[position + d + N[position + d]]) {
      position = position + d + N[position + d];
      output = 1;
    } else if (isPositionValid(position - d) && path[position] > path[position - d + N[position - d]]) {
      position = position - d + N[position - d];
      output = -1;
    } else {
      output = 0;
    }
    cout << output << endl;
  }

  delete[] N;

  return 0;
}
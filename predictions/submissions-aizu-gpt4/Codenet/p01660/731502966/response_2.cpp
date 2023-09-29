#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal;
vector<int> dice(6), N, path(MAX_M, MAX_T + 1), visit(MAX_M, false);
bool isPositionValid(int p) { return 0 <= p && p < M; }
void MakePath(int from) {
  path[from] = (from == goal) ? 0 : MAX_T;
  visit[from] = true;
  for (int r = 0; r < 6; r++) {
    int moveto = from + dice[r];
    if (isPositionValid(moveto) && !visit[moveto]) {
      MakePath(moveto);
      path[from] = min(path[from], path[moveto] + 1);
    }
    moveto = from - dice[r];
    if (isPositionValid(moveto) && !visit[moveto]) {
      MakePath(moveto);
      path[from] = min(path[from], path[moveto] + 1);
    }
  }
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
  MakePath(start);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int output = 0;
    int moveto = position + d;
    if (isPositionValid(moveto) && path[position] > path[moveto + N[moveto]]) {
      position = moveto + N[moveto];
      output = 1;
    } else {
      moveto = position - d;
      if (isPositionValid(moveto) && path[position] > path[moveto + N[moveto]]) {
        position = moveto + N[moveto];
        output = -1;
      }
    }
    cout << output << endl;
  }
  return 0;
}
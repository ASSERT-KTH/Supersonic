#include <iostream>
#include <vector>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6];
vector<int> N, path(MAX_M, MAX_T + 1), visit(MAX_M, false);
bool isPositionValid(int p) { return 0 <= p && p < M; }
void MakePath(int from) {
  visit[from] = true;
  int bestpath = MAX_T;
  if (from == goal)
    bestpath = 0;
  else {
    for (int r = 0; r < 6; r++) {
      int moveto = from + dice[r];
      if (isPositionValid(moveto) && !visit[moveto]) {
        MakePath(moveto);
        bestpath = min(bestpath, path[moveto] + 1);
      }
      moveto = from - dice[r];
      if (isPositionValid(moveto) && !visit[moveto]) {
        MakePath(moveto);
        bestpath = min(bestpath, path[moveto] + 1);
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
    int output;
    if (isPositionValid(position + d) && path[position] > path[position + d + N[position + d]]) {
      position = position + d + N[position + d];
      output = 1;
    }
    else if (isPositionValid(position - d) && path[position] > path[position - d + N[position - d]]) {
      position = position - d + N[position - d];
      output = -1;
    }
    else
      output = 0;
    cout << output << endl;
  }
  return 0;
}
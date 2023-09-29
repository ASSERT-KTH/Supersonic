#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], *N;
bool isPositionValid(int p) { return 0 <= p && p < M; }
int *MakePath(int *path, int from, bool visit[]) {
  static auto checkPath = [&](int moveto) -> int {
    if (!isPositionValid(moveto)) return 2 * MAX_T;
    int position = moveto + N[moveto];
    if (!visit[position]) {
      visit[position] = 1;
      path[position] = MakePath(path, position, visit)[position];
    }
    return path[position] + 1;
  };
  int bestpath = MAX_T;
  if (from == goal) bestpath = 0;
  else {
    for (int r = 0; r < 6; r++) {
      bestpath = min(bestpath, checkPath(from + dice[r]));
      bestpath = min(bestpath, checkPath(from - dice[r]));
    }
  }
  path[from + N[from]] = bestpath;
  return path;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> M;
  for (int r = 0; r < 6; r++) cin >> dice[r];
  cin >> start >> goal;
  start--, goal--;
  N = new int[M];
  for (int m = 0; m < M; m++) cin >> N[m];
  bool visit[MAX_M] = {};
  int *path = new int[M * 2 + 1]();
  for (int m = 0; m < M; m++) path[m] = MAX_T + 1;
  visit[start + N[start]] = true;
  path[start + N[start]] = 0;
  path = MakePath(path, start, visit);
  int position = start;
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal) break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int output = 0;
    int to = position + d + N[position + d];
    if (isPositionValid(position + d) && path[position + N[position + d]] < path[position + N[position]] && path[position + N[position + d]] <= MAX_T) {
      output = 1;
      position = to;
    } else {
      to = position - d + N[position - d];
      if (isPositionValid(position - d) && path[position + N[position - d]] < path[position + N[position]] && path[position + N[position - d]] <= MAX_T) {
        output = -1;
        position = to;
      }
    }
    cout << output << endl;
  }
  delete[] N;
  delete[] path;
  return 0;
}
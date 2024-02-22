#include <iostream>
#include <queue>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;
int M, start, goal, dice[6], *N;
bool isPositionValid(int p) { return 0 <= p && p < M; }

void MakePath(int *path, int from) {
  static bool visit[MAX_M] = {};
  queue<int> q;
  q.push(from);
  visit[from] = true;
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    int bestpath = cur == goal ? 0 : MAX_T;
    for (int r = 0; r < 6; r++) {
      int moveto = cur + dice[r];
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        if (!visit[position]) {
          visit[position] = true;
          q.push(position);
        }
        bestpath = min(bestpath, path[position] + 1);
      }
      moveto = cur - dice[r];
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        if (!visit[position]) {
          visit[position] = true;
          q.push(position);
        }
        bestpath = min(bestpath, path[position] + 1);
      }
    }
    path[cur] = bestpath;
  }
}

int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
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
  auto tryMove = [&path](int moveto, int path_before,
                         int &position) -> bool {
    if (isPositionValid(moveto)) {
      if (path_before > path[moveto + N[moveto]]) {
        position = moveto + N[moveto];
        return true;
      }
    }
    return false;
  };
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    int r;
    cin >> r;
    int d = dice[r - 1];
    int output;
    if (tryMove(position + d, path[position], position))
      output = 1;
    else if (tryMove(position - d, path[position], position))
      output = -1;
    else
      output = 0;
    cout << output << endl;
  }
  delete[] N;
  return 0;
}
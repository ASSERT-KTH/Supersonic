#include <iostream>
using namespace std;
const int MAX_T = 3000, MAX_M = 300;

bool isPositionValid(int p, int M) {
  return 0 <= p && p < M;
}

int* MakePath(int* path, int from, int goal, int M, int* N, int* dice) {
  bool* visit = new bool[M]();
  
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
      if (isPositionValid(moveto, M)) {
        int position = moveto + N[moveto];
        if (!visit[position])
          MakePath(path, position, goal, M, N, dice);
        bestpath = min(bestpath, path[position] + 1);
      }
      
      moveto = from - dice[r];
      if (isPositionValid(moveto, M)) {
        int position = moveto + N[moveto];
        if (!visit[position])
          MakePath(path, position, goal, M, N, dice);
        bestpath = min(bestpath, path[position] + 1);
      }
    }
  }
  
  path[from] = bestpath;
  delete[] visit;
  return path;
}

void tryMove(int moveto, int path_before, int& position, int* path, int* N) {
  if (isPositionValid(moveto, position)) {
    if (path_before > path[moveto + N[moveto]]) {
      position = moveto + N[moveto];
    }
  }
}

int main() {
  int M, start, goal;
  cin >> M;
  
  int dice[6];
  for (int r = 0; r < 6; r++)
    cin >> dice[r];
    
  cin >> start >> goal;
  start--, goal--;
  
  int* N = new int[M];
  for (int m = 0; m < M; m++)
    cin >> N[m];
    
  int* path = MakePath(NULL, start, goal, M, N, dice);
  int position = start;
  
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
      
    int r;
    cin >> r;
    int d = dice[r - 1];
    
    int moveto = position + d;
    tryMove(moveto, path[position], position, path, N);
    
    moveto = position - d;
    tryMove(moveto, path[position], position, path, N);
    
    int output = (position == goal ? 0 : (moveto == position + d ? 1 : -1));
    cout << output << endl;
  }
  
  delete[] N;
  delete[] path;
  return 0;
}
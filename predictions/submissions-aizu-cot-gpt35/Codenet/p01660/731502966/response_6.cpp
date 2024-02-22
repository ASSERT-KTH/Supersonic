#include <iostream>
using namespace std;

const int MAX_T = 3000, MAX_M = 300;

int M, start, goal, dice[6], *N;

bool isPositionValid(int p) {
  return p >= 0 && p < M;
}

void MakePath(int *path, int from) {
  bool visit[MAX_M] = {};
  
  if (path == nullptr) {
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
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        if (!visit[position])
          MakePath(path, position);
        bestpath = min(bestpath, path[position] + 1);
      }
      
      moveto = from - dice[r];
      if (isPositionValid(moveto)) {
        int position = moveto + N[moveto];
        if (!visit[position])
          MakePath(path, position);
        bestpath = min(bestpath, path[position] + 1);
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
  
  N = new int[M];
  
  for (int m = 0; m < M; m++)
    cin >> N[m];
  
  int *path = new int[M];
  for (int m = 0; m < M; m++)
    path[m] = MAX_T + 1;
  
  MakePath(path, start);
  
  int position = start;
  
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal)
      break;
    
    int r;
    cin >> r;
    int d = dice[r - 1];
    
    int moveto = position + d;
    if (isPositionValid(moveto)) {
      if (path[position] > path[moveto + N[moveto]])
        position = moveto + N[moveto];
    }
    
    moveto = position - d;
    if (isPositionValid(moveto)) {
      if (path[position] > path[moveto + N[moveto]])
        position = moveto + N[moveto];
    }
    
    int output = (position == goal) ? 0 : ((position > goal) ? -1 : 1);
    cout << output << endl;
  }
  
  delete[] N;
  delete[] path;
  
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX_T = 3000;
constexpr int MAX_M = 300;

int M, start, goal;
vector<int> dice(6);
vector<int> N;

int MakePath(vector<int>& path, int from) {
  vector<bool> visited(M, false);
  
  if (path.empty()) {
    path.resize(M, MAX_T + 1);
  }
  
  visited[from] = true;
  int bestpath = MAX_T;
  
  if (from == goal) {
    bestpath = 0;
  } else {
    for (int r = 0; r < 6; r++) {
      int moveto = from + dice[r];
      if (moveto >= 0 && moveto < M) {
        int position = moveto + N[moveto];
        if (!visited[position]) {
          MakePath(path, position);
        }
        bestpath = min(bestpath, path[position] + 1);
      }
      
      moveto = from - dice[r];
      if (moveto >= 0 && moveto < M) {
        int position = moveto + N[moveto];
        if (!visited[position]) {
          MakePath(path, position);
        }
        bestpath = min(bestpath, path[position] + 1);
      }
    }
  }
  
  path[from] = bestpath;
  return bestpath;
}

int main() {
  cin >> M;
  
  for (int r = 0; r < 6; r++) {
    cin >> dice[r];
  }
  
  cin >> start >> goal;
  start--, goal--;
  
  N.resize(M);
  for (int m = 0; m < M; m++) {
    cin >> N[m];
  }
  
  vector<int> path;
  MakePath(path, start);
  
  int position = start;
  
  for (int t = 0; t < MAX_T; t++) {
    if (position == goal) {
      break;
    }
    
    int r;
    cin >> r;
    int d = dice[r - 1];
    
    bool moved = false;
    
    if (position + d < M && path[position] > path[position + d + N[position + d]]) {
      position = position + d + N[position + d];
      moved = true;
    }
    
    if (!moved && position - d >= 0 && path[position] > path[position - d + N[position - d]]) {
      position = position - d + N[position - d];
      moved = true;
    }
    
    cout << (moved ? (position < goal ? 1 : -1) : 0) << '\n';
  }
  
  return 0;
}
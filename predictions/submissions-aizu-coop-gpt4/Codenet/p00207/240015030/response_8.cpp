#include <iostream>
using namespace std;

int** Board;
bool isOK;
int xs, ys, xg, yg;
int w_prev = 0, h_prev = 0;

void DFS(int c, int x, int y) {
  if (Board[x][y] != c) {
    return;
  } else if (x == xg && y == yg) {
    isOK = true;
    return;
  }
  Board[x][y] = 0;
  DFS(c, x + 1, y);
  DFS(c, x, y + 1);
  DFS(c, x - 1, y);
  DFS(c, x, y - 1);
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
    
    isOK = false;
    
    if (w != w_prev || h != h_prev) {
      // Deallocate previous Board
      for (int i = 0; i < h_prev; i++) {
        delete[] Board[i];
      }
      delete[] Board;

      // Allocate new Board
      Board = new int*[h];
      for (int i = 0; i < h; i++) {
        Board[i] = new int[w];
      }
      
      w_prev = w;
      h_prev = h;
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++)
        Board[j][i] = -1;
    }
    
    cin >> xs >> ys >> xg >> yg;
    int n, c, d, x, y;
    cin >> n;
    for (int t = 0; t < n; t++) {
      cin >> c >> d >> x >> y;
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          Board[x + j][y + i] = c;
      }
    }
    DFS(Board[xs][ys], xs, ys);
    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  
  // Deallocate Board at the end of the program
  for (int i = 0; i < h_prev; i++) {
    delete[] Board[i];
  }
  delete[] Board;
  
  return 0;
}
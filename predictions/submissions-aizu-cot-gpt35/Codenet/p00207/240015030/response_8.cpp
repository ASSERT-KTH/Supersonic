#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

void DFS(vector<vector<int>>& Board, int c, int x, int y, bool& isOK) {
  int w = Board.size();
  int h = Board[0].size();
  
  if (Board[x][y] != c) {
    return;
  } else if (x == w - 1 && y == h - 1) {
    isOK = true;
    return;
  }
  
  Board[x][y] = 0;
  
  vector<int> dx = {1, 0, -1, 0};
  vector<int> dy = {0, 1, 0, -1};
  
  vector<int> stack_x;
  vector<int> stack_y;
  
  stack_x.push_back(x);
  stack_y.push_back(y);
  
  while (!stack_x.empty()) {
    int curr_x = stack_x.back();
    int curr_y = stack_y.back();
    
    stack_x.pop_back();
    stack_y.pop_back();
    
    for (int i = 0; i < 4; i++) {
      int new_x = curr_x + dx[i];
      int new_y = curr_y + dy[i];
      
      if (new_x >= 0 && new_x < w && new_y >= 0 && new_y < h && Board[new_x][new_y] == c) {
        stack_x.push_back(new_x);
        stack_y.push_back(new_y);
        Board[new_x][new_y] = 0;
        
        if (new_x == w - 1 && new_y == h - 1) {
          isOK = true;
          return;
        }
      }
    }
  }
}

int main() {
  int w, h;
  while (true) {
    cin >> w >> h;
    if (w == 0 && h == 0)
      break;
      
    vector<vector<int>> Board(w, vector<int>(h, -1));
    
    int xs, ys, xg, yg;
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
    
    bool isOK = false;
    DFS(Board, Board[xs][ys], xs, ys, isOK);
    
    if (isOK)
      cout << "OK" << endl;
    else
      cout << "NG" << endl;
  }
  return 0;
}
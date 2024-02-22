#include <iostream>
#include <stack>
using namespace std;

bool** maze;
bool** visited;
int W, H;

void meiro(int xs, int ys, int c) {
  stack<pair<int, int>> st;
  st.push({xs, ys});
  
  while (!st.empty()) {
    int x = st.top().first;
    int y = st.top().second;
    st.pop();
    
    if (visited[x][y]) {
      continue;
    }
    
    visited[x][y] = true;
    
    if (x == W && y == H) {
      return;
    }
    
    if (x > 0 && maze[x-1][y] == c) {
      st.push({x-1, y});
    }
    if (y < H && maze[x][y+1] == c) {
      st.push({x, y+1});
    }
    if (x < W && maze[x+1][y] == c) {
      st.push({x+1, y});
    }
    if (y > 0 && maze[x][y-1] == c) {
      st.push({x, y-1});
    }
  }
}

int main() {
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }
    
    W = w;
    H = h;
    
    // Create maze and visited arrays
    maze = new bool*[w+1];
    visited = new bool*[w+1];
    for (int i = 0; i <= w; i++) {
      maze[i] = new bool[h+1];
      visited[i] = new bool[h+1];
      for (int j = 0; j <= h; j++) {
        maze[i][j] = false;
        visited[i][j] = false;
      }
    }
    
    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    int n;
    cin >> n;
    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      
      for (int j = x; j < x + 4; j++) {
        for (int k = y; k < y + 4; k++) {
          if (j <= w && k <= h) {
            maze[j][k] = true;
          }
        }
      }
    }
    
    meiro(xs, ys, maze[xs][ys]);
    
    if (visited[xg][yg]) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
    
    // Deallocate maze and visited arrays
    for (int i = 0; i <= w; i++) {
      delete[] maze[i];
      delete[] visited[i];
    }
    delete[] maze;
    delete[] visited;
  }
  return 0;
}
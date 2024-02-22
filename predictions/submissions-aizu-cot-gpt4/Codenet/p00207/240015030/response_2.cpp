#include <cstdio>
#include <stack>
using namespace std;
bool isOK;
int xs, ys, xg, yg;
int Board[102][102];
struct State { int c, x, y; };
stack<State> dfs_stack;
void DFS(int c) {
  while(!dfs_stack.empty()){
    State s = dfs_stack.top(); dfs_stack.pop();
    int x = s.x, y = s.y;
    if(Board[x][y] != c || x < 0 || x > 101 || y < 0 || y > 101){
      continue;
    } else if (x == xg && y == yg) {
      isOK = true;
      return;
    }
    Board[x][y] = 0;
    dfs_stack.push({c, x+1, y});
    dfs_stack.push({c, x, y+1});
    dfs_stack.push({c, x-1, y});
    dfs_stack.push({c, x, y-1});
  }
}
int main() {
  int w, h;
  while (true) {
    scanf("%d %d", &w, &h);
    if (w == 0 && h == 0)
      break;
    isOK = false;
    scanf("%d %d %d %d", &xs, &ys, &xg, &yg);
    int n, c, d, x, y;
    scanf("%d", &n);
    for (int t = 0; t < n; t++) {
      scanf("%d %d %d %d", &c, &d, &x, &y);
      int wb = 2 + (!d * 2);
      int hb = 2 + (d * 2);
      for (int i = 0; i < hb; i++) {
        for (int j = 0; j < wb; j++)
          Board[x + j][y + i] = c;
      }
    }
    dfs_stack.push({Board[xs][ys], xs, ys});
    DFS(Board[xs][ys]);
    if (isOK)
      printf("OK\n");
    else
      printf("NG\n");
  }
  return 0;
}
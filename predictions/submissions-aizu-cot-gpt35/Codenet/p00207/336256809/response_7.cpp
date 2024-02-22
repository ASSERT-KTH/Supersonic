#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }
    
    vector<vector<int>> C(w+2, vector<int>(h+2, 10));

    int xs, ys, xg, yg;
    cin >> xs >> ys >> xg >> yg;
    
    int n;
    cin >> n;
    
    int c, d, x, y;
    for (int i = 0; i < n; i++) {
      cin >> c >> d >> x >> y;
      if (d == 0) {
        for (int j = x; j < x + 4; j++) {
          for (int k = y; k < y + 2; k++) {
            C[j][k] = c;
          }
        }
      } else {
        for (int j = x; j < x + 2; j++) {
          for (int k = y; k < y + 4; k++) {
            C[j][k] = c;
          }
        }
      }
    }
    
    queue<pair<int, int>> q;
    q.push({xs, ys});
    C[xs][ys] = -1;
    
    while (!q.empty()) {
      int W = q.front().first;
      int H = q.front().second;
      q.pop();
      
      if (W == xg && H == yg) {
        break;
      }
      
      if (C[W-1][H] == C[xs][ys]) {
        C[W-1][H] = -1;
        q.push({W-1, H});
      }
      if (C[W][H+1] == C[xs][ys]) {
        C[W][H+1] = -1;
        q.push({W, H+1});
      }
      if (C[W+1][H] == C[xs][ys]) {
        C[W+1][H] = -1;
        q.push({W+1, H});
      }
      if (C[W][H-1] == C[xs][ys]) {
        C[W][H-1] = -1;
        q.push({W, H-1});
      }
    }
    
    if (C[xg][yg] == -1) {
      cout << "OK" << endl;
    } else {
      cout << "NG" << endl;
    }
  }
  
  return 0;
}
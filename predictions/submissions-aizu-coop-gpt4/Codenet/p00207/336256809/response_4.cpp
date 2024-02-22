#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void meiro(vector<vector<int>>& C, int W, int H, int c) {
  stack<pair<int, int>> s;
  s.push({W, H});
  
  while (!s.empty()) {
    pair<int, int> p = s.top();
    s.pop();
    int W = p.first, H = p.second;
    
    if (C[W][H] != c) {
      continue;
    }
    
    C[W][H] = -1;
    s.push({W - 1, H});
    s.push({W, H + 1});
    s.push({W + 1, H});
    s.push({W, H - 1});
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  vector<vector<int>> C(102, vector<int>(102));
  
  while (1) {
    int w, h;
    cin >> w >> h;
    if (w == 0 && h == 0) {
      break;
    }
    
    fill(C.begin(), C.end(), vector<int>(102, 10));
    
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
    meiro(C, xs, ys, C[xs][ys]);
    if (C[xg][yg] == -1) {
      cout << "OK\n";
    } else {
      cout << "NG\n";
    }
  }
  
  return 0;
}
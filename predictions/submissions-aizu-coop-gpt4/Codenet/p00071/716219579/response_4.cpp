#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;
typedef pair<int, int> P;

int n, y, x, M[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void solve(int y, int x) {
  queue<P> q;
  q.push(P(y, x));
  M[y][x] = 0;
  
  while (!q.empty()) {
    P pos = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= 3; j++) {
        int ny = pos.first + dy[i] * j, nx = pos.second + dx[i] * j;
        if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1) {
          M[ny][nx] = 0;
          q.push(P(ny, nx));
        }
      }
    }
  }
}

int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 8; j++) {
      string s;
      cin >> s;
      for (int k = 0; k < 8; k++) { 
        M[j][k] = s[k] - '0'; 
      }
    }
  
    cin >> x >> y;
    solve(y - 1, x - 1);

    cout << "Data " << i + 1 << ":" << endl;
    for (int j = 0; j < 8; j++) {
      for (int k = 0; k < 8; k++) { 
        cout << M[j][k];
      }
      cout << endl;
    }
  }
}
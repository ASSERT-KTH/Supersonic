#include <iostream>
#include <vector>
using namespace std;
#define REP(i, N) for (int i = 0; i < (N); i++)
typedef vector<int> V;
int M[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void solve(int y, int x) {
  M[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y, nx = x;
    for (int j = 1; j <= 3; j++) {
      ny += dy[i]; nx += dx[i];
      if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
        if (M[ny][nx] == 1)
          solve(ny, nx);
      }
    }
  }
}
int main() {
  int n;
  cin >> n;
  REP(i, n) {
    string s;
    REP(j, 8) {
      cin >> s;
      REP(k, 8) { M[j][k] = s[k] - '0'; }
    }
    int x, y;
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << i + 1 << ":" << endl;
    REP(j, 8) {
      REP(k, 8) { cout << M[j][k]; }
      cout << endl;
    }
  }
}
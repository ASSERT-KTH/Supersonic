#include <iostream>
#include <vector>
using namespace std;
#define REP(i, N) for (int i = 0; i < (N); i++)
typedef vector<int> V;
int n, y, x, M[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
void solve(int y, int x) {
  M[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx]) {
      solve(ny, nx);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  REP(i, n) {
    REP(j, 8) {
      REP(k, 8) { cin >> M[j][k]; }
    }
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << i + 1 << ":\n";
    REP(j, 8) {
      REP(k, 8) { cout << M[j][k]; }
      cout << '\n';
    }
  }
  return 0;
}
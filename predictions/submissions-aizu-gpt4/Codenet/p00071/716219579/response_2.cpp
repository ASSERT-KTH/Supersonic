#include <iostream>
#include <vector>
using namespace std;
#define REP(i, N) for (long long i = 0; i < (N); i++)
typedef vector<int> V;
int n, x, y;
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
vector<V> M(8, V(8));
void solve(int y, int x) {
  M[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 3; j++) {
      int ny = y + dy[i] * j, nx = x + dx[i] * j;
      if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1) solve(ny, nx);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  REP(i, n) {
    REP(j, 8) {
      string s;
      cin >> s;
      REP(k, 8) { M[j][k] = s[k] - '0'; }
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
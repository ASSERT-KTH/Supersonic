#include <bits/stdc++.h>
using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, N) for (int i = 0; i < (N); i++)
#define ALL(s) (s).begin(), (s).end()

int n;
int y, x, M[9][9];
const int dx[] = {1, 0, -1, 0};
const int dy[] = {0, 1, 0, -1};

void solve(int y, int x) {
  M[y][x] = 0;
  FOR(i, 0, 4) {
    FOR(j, 1, 4) {
      int ny = y + dy[i] * j, nx = x + dx[i] * j;
      if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8) {
        if (M[ny][nx] == 1)
          solve(ny, nx);
      }
    }
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  REP(i, n) {
    REP(j, 8) {
      REP(k, 8) { cin >> M[j][k]; }
    }
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << i + 1 << ":" << endl;
    REP(j, 8) {
      REP(k, 8) { cout << M[j][k]; }
      cout << endl;
    }
  }
  return 0;
}
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<ll> V;
int n, y, x, M[9][9];
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
void solve(int y, int x) {
  M[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    int ny = y + dy[i], nx = x + dx[i];
    if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1)
        solve(ny, nx);
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < 8; j++) {
      for(int k = 0; k < 8; k++) {
        char c;
        cin >> c;
        M[j][k] = c - '0';
      }
    }
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << i + 1 << ":\n";
    for(int j = 0; j < 8; j++) {
      for(int k = 0; k < 8; k++)
        cout << M[j][k];
      cout << '\n';
    }
  }
}
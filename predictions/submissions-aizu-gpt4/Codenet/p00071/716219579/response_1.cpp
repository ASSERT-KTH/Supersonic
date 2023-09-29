#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
typedef vector<ll> V;
string s;
int n;
int y, x, M[9][9];
int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};
inline void solve(int y, int x) {
  M[y][x] = 0;
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 3; j++) {
      int ny = y + dy[i] * j, nx = x + dx[i] * j;
      if (ny >= 0 && ny < 8 && nx >= 0 && nx < 8 && M[ny][nx] == 1)
          solve(ny, nx);
    }
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  while(n--) {
    for(int j = 0; j < 8; ++j) {
      cin >> s;
      for(int k = 0; k < 8; ++k) { M[j][k] = s[k] - '0'; }
    }
    cin >> x >> y;
    solve(y - 1, x - 1);
    cout << "Data " << n + 1 << ":\n";
    for(int j = 0; j < 8; ++j) {
      for(int k = 0; k < 8; ++k) { cout << M[j][k]; }
      cout << '\n';
    }
  }
}
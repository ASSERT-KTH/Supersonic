#include <iostream>
#include <vector>
using namespace std;

const int MAX_H = 1001;
const int MAX_W = 1001;

vector<vector<bool>> mp(MAX_H, vector<bool>(MAX_W));
vector<vector<int>> dp(MAX_H, vector<int>(MAX_W));

int h, w, n;

void saiki(int x, int y) {
  int dx[] = {0, 1};
  int dy[] = {1, 0};

  while (y != h && x != w) {
    int nx = x + dx[mp[y][x]];
    int ny = y + dy[mp[y][x]];
    x = nx;
    y = ny;
  }

  cout << y + 1 << " " << x + 1 << endl;
}

int main() {
  while (1) {
    cin >> h >> w >> n;
    if (!h && !w && !n)
      break;

    for (int i = 0; i < h; i++)
      for (int j = 0; j < w; j++)
        cin >> mp[i][j];

    dp[0][0] = n - 1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * (dp[i][j] & 1);
        dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * (dp[i][j] & 1);
        mp[i][j] ^= (dp[i][j] & 1);
      }
    }

    saiki(0, 0);
  }

  return 0;
}
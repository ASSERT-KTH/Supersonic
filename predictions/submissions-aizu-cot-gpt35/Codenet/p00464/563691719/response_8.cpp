#include <iostream>
using namespace std;

const int MAX_SIZE = 1001;
int mp[MAX_SIZE][MAX_SIZE];
int dp[MAX_SIZE][MAX_SIZE];

void saiki(int h, int w, int n) {
  int dx[] = {0, 1};
  int dy[] = {1, 0};

  int x = 0, y = 0;
  while (y != h && x != w) {
    x += dx[mp[y][x]];
    y += dy[mp[y][x]];
  }

  cout << y + 1 << " " << x + 1 << "\n";
}

int main() {
  while (true) {
    int h, w, n;
    cin >> h >> w >> n;

    if (h == 0 && w == 0 && n == 0)
      break;

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        cin >> mp[i][j];
      }
    }

    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        dp[i][j] = 0;
      }
    }

    dp[0][0] = n - 1;
    for (int i = 0; i < h; i++) {
      for (int j = 0; j < w; j++) {
        int dp_mod_2 = dp[i][j] % 2;

        dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * dp_mod_2;
        dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * dp_mod_2;

        if (dp_mod_2) {
          mp[i][j] = !mp[i][j];
        }
      }
    }

    saiki(h, w, n);
  }

  return 0;
}
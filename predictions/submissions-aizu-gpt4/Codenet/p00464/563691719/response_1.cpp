#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<int>> mp(1001, vector<int>(1001, 0));
vector<vector<int>> dp(1001, vector<int>(1001, 0));
int h, w, n;

void saiki(int x, int y) {
    const int dx[2] = {0, 1}, dy[2] = {1, 0};
    if (y == h || x == w)
        cout << y + 1 << " " << x + 1 << endl;
    else
        saiki(x + dx[mp[y][x]], y + dy[mp[y][x]]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    while (cin >> h >> w >> n && (h || w || n)) {
        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j)
                cin >> mp[i][j];

        fill(dp.begin(), dp.end(), vector<int>(1001, 0));
        dp[0][0] = n - 1;

        for (int i = 0; i < h; ++i)
            for (int j = 0; j < w; ++j) {
                int half = dp[i][j] / 2;
                int rem = dp[i][j] % 2;
                dp[i][j + 1] += half + rem * mp[i][j];
                dp[i + 1][j] += half + rem * (1 - mp[i][j]);
                if (rem)
                    mp[i][j] ^= 1;
            }
        saiki(0, 0);
    }
    return 0;
}
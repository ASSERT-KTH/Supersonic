#include <iostream>
#include <cstring>

using namespace std;

const int MAX_H = 1001;
const int MAX_W = 1001;

int mp[MAX_H][MAX_W], dp[MAX_H][MAX_W];
int h, w, n;

int main() {
    while (1) {
        cin >> h >> w >> n;
        if (!h && !w && !n)
            break;
        
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                cin >> mp[i][j];

        memset(dp, 0, sizeof(dp));
        dp[0][0] = n - 1;

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int next_x = j + mp[i][j];
                int next_y = i + !mp[i][j];

                if (next_x < w)
                    dp[i][next_x] += dp[i][j] / 2 + mp[i][j] * (dp[i][j] % 2);
                if (next_y < h)
                    dp[next_y][j] += dp[i][j] / 2 + (!mp[i][j]) * (dp[i][j] % 2);

                if (dp[i][j] % 2)
                    mp[i][j] = !mp[i][j];
            }
        }
    }
    return 0;
}
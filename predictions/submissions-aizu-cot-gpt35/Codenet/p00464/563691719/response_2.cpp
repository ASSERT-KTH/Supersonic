#include <iostream>
using namespace std;

const int MAX_N = 1001;
int mp[MAX_N][MAX_N], dp[MAX_N][MAX_N];

int h, w, n;

void saiki(int x, int y) {
    int dx[] = {0, 1}, dy[] = {1, 0};
    while (y < h && x < w) {
        x += dx[mp[y][x]];
        y += dy[mp[y][x]];
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

        // Initialize dp[][] directly
        for (int i = 0; i <= h; i++) {
            for (int j = 0; j <= w; j++) {
                dp[i][j] = 0;
            }
        }

        dp[0][0] = n - 1;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                int half = dp[i][j] / 2;
                int mod = dp[i][j] % 2;
                dp[i][j + 1] += half + mp[i][j] * mod;
                dp[i + 1][j] += half + !mp[i][j] * mod;
                if (mod)
                    mp[i][j] = !mp[i][j];
            }
        }
        saiki(0, 0);
    }
    return 0;
}
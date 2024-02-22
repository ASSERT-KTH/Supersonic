#include <iostream>
#include <vector>

int main() {
    while (1) {
        int h, w, n;
        std::cin >> h >> w >> n;
        if (!h && !w && !n)
            break;
        std::vector<std::vector<int>> mp(h, std::vector<int>(w));
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++)
                std::cin >> mp[i][j];
        std::vector<std::vector<int>> dp(h, std::vector<int>(w, 0));
        dp[0][0] = n - 1;
        for (int i = 0; i < h; i++)
            for (int j = 0; j < w; j++) {
                dp[i][j + 1] += dp[i][j] / 2 + mp[i][j] * dp[i][j] % 2;
                dp[i + 1][j] += dp[i][j] / 2 + !mp[i][j] * dp[i][j] % 2;
                if (dp[i][j] % 2)
                    mp[i][j] = !mp[i][j];
            }
        int x = 0, y = 0;
        while(y != h && x != w) {
            int dx[] = {0, 1}, dy[] = {1, 0};
            x += dx[mp[y][x]];
            y += dy[mp[y][x]];
        }
        std::cout << y + 1 << " " << x + 1 << std::endl;
    }
    return 0;
}
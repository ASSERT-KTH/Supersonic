#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int MAXN = 8;
int w, h, Col;
vector<vector<int>> V;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
int res;
void dfs(int y, int x, int color, vector<vector<int>>& grid, bool used[MAXN][MAXN]) {
    if (y < 0 || x < 0 || x >= w || y >= h)
        return;
    if (used[y][x] || grid[y][x] != color)
        return;
    used[y][x] = true;
    dfs(y + dy[0], x + dx[0], color, grid, used);
    dfs(y + dy[1], x + dx[1], color, grid, used);
    dfs(y + dy[2], x + dx[2], color, grid, used);
    dfs(y + dy[3], x + dx[3], color, grid, used);
}
void on(vector<vector<int>> grid, int count, int c) {
    if (count == 5) {
        int ans = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] == c) {
                    bool used[MAXN][MAXN];
                    memset(used, false, sizeof(used));
                    dfs(i, j, c, grid, used);
                    ans += 1;
                }
            }
        }
        res = max(res, ans);
        return;
    }
    int nc = grid[0][0];
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (grid[i][j] == nc) {
                vector<vector<int>> newGrid = grid;
                newGrid[i][j] = c;
                on(newGrid, count + 1, c + 1);
            }
        }
    }
}
void solve() {
    res = 0;
    V.clear();
    V.resize(h);
    for (int y = 0; y < h; y++) {
        V[y].resize(w);
        for (int x = 0; x < w; x++) {
            cin >> V[y][x];
        }
    }
    for (int i = 1; i <= 6; i++) {
        if (V[0][0] != i)
            on(V, 0, i);
    }
    cout << res << endl;
}
int main() {
    while (cin >> h >> w >> Col) {
        if (w == 0)
            break;
        solve();
    }
    return 0;
}
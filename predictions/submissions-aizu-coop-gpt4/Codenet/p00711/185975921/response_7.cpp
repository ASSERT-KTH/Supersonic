#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int y, int x, vector<vector<char>>& mp, int H, int W) {
    stack<pair<int, int>> st;
    st.push({y, x});
    while (!st.empty()) {
        auto [curY, curX] = st.top();
        st.pop();
        if (curY < 0 || curY >= H || curX < 0 || curX >= W || mp[curY][curX] == '#' || mp[curY][curX] == ' ')
            continue;
        mp[curY][curX] = ' ';
        st.push({curY - 1, curX});
        st.push({curY + 1, curX});
        st.push({curY, curX - 1});
        st.push({curY, curX + 1});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int H, W;
    while (cin >> W >> H, H || W) {
        vector<vector<char>> mp(H, vector<char>(W));
        int sy, sx;
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                cin >> mp[i][j];
                if (mp[i][j] == '@')
                    sy = i, sx = j, mp[i][j] = '.';
            }
        }
        dfs(sy, sx, mp, H, W);
        int cnt = 0;
        for (const auto& row : mp)
            for (const auto& cell : row)
                if (cell == ' ') cnt++;
        cout << cnt << '\n';
    }
    return 0;
}
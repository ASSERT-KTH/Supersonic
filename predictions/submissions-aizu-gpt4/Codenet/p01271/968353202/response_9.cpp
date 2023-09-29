#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct pos {
    short lx, ly, rx, ry;
};

constexpr short dx[4] = {0, 0, 1, -1};
constexpr short dy[4] = {1, -1, 0, 0};

int main() {
    short w, h;
    while (cin >> w >> h && (w || h)) {
        vector<vector<char>> mp[2];
        vector<vector<vector<vector<bool>>>> visited(51, vector<vector<vector<bool>>>(51, vector<vector<bool>>(51, vector<bool>(51, false))));
        for (short i = 0; i < 2; ++i) {
            mp[i].resize(h, vector<char>(w));
            for (short j = 0; j < h; ++j)
                for (short k = 0; k < w; ++k)
                    cin >> mp[i][j][k];
        }
        pos start{};
        for (short i = 0; i < h; ++i)
            for (short j = 0; j < w; ++j) {
                if (mp[0][i][j] == 'L')
                    start.lx = j, start.ly = i;
                if (mp[1][i][j] == 'R')
                    start.rx = j, start.ry = i;
            }
        queue<pos> Q;
        Q.push(start);
        bool found = false;
        while (!Q.empty()) {
            pos t = Q.front();
            Q.pop();
            short cnt = (mp[0][t.ly][t.lx] == '%') + (mp[1][t.ry][t.rx] == '%');
            if (cnt == 2) {
                found = true;
                break;
            }
            if (visited[t.lx][t.ly][t.rx][t.ry] || cnt == 1)
                continue;
            visited[t.lx][t.ly][t.rx][t.ry] = true;
            for (short i = 0; i < 4; ++i) {
                short flg = 0;
                short nlx = t.lx + dx[i], nly = t.ly + dy[i];
                short nrx = t.rx - dx[i], nry = t.ry - dy[i];
                if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#')
                    nlx = t.lx, nly = t.ly, ++flg;
                if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#')
                    nrx = t.rx, nry = t.ry, ++flg;
                if (flg < 2)
                    Q.push({nlx, nly, nrx, nry});
            }
        }
        cout << (found ? "Yes\n" : "No\n");
    }
    return 0;
}
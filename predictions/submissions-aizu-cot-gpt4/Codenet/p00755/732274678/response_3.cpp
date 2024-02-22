#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <array>
using namespace std;

void solve() {
    int w, h, Col;
    cin >> h >> w >> Col;
    if (w == 0) return;

    typedef array<int, 2> C;
    typedef vector<vector<int>> P;
    P V;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    int res = 0;
    P temp;
    int tres = 0;

    auto calc = [&](int y, int x) {
        vector<C> stack = {{y, x}};
        while (!stack.empty()) {
            tie(y, x) = stack.back(); stack.pop_back();
            if (y < 0 || x < 0 || x >= w || y >= h || temp[y][x] != Col)
                continue;
            tres++;
            temp[y][x] = 0;
            for (int r = 0; r < 4; r++)
                stack.push_back({y + dy[r], x + dx[r]});
        }
    };

    function<void(P&, int, int)> on;
    on = [&](P& N, int count, int c) {
        if (count == 5) {
            temp = N;
            tres = 0;
            calc(0, 0);
            res = max(res, tres);
            return;
        }
        int nc = N[0][0];
        vector<C> Q = {{0, 0}};
        bool used[8][8];
        memset(used, false, sizeof(used));
        int tres = 0;
        while (!Q.empty()) {
            C now = Q.back(); Q.pop_back();
            if (used[now[0]][now[1]]) continue;
            used[now[0]][now[1]] = true;
            N[now[0]][now[1]] = c;
            for (int r = 0; r < 4; r++) {
                int ny = now[0] + dy[r], nx = now[1] + dx[r];
                if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
                if (N[ny][nx] == nc)
                    Q.push_back({ny, nx});
            }
        }
        if (count != 4)
            for (int i = 1; i <= 6; i++)
                on(N, count + 1, i);
        else
            on(N, count + 1, Col);
    };

    V.clear();
    V.resize(h);
    for (int y = 0; y < h; y++)
        for (int x = 0; x < w; x++) {
            int t;
            cin >> t;
            V[y].push_back(t);
        }
    for (int i = 1; i <= 6; i++) {
        if (V[0][0] != i)
            on(V, 0, i);
    }
    cout << res << endl;
}

int main() {
    while (true) {
        solve();
    }
    return 0;
}
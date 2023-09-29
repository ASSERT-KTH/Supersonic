#include <iostream>
#include <vector>
#include <array>
#include <stack>

using namespace std;

array<array<int, 102>, 102> C;
array<pair<int, int>, 4> directions = {{{-1, 0}, {0, 1}, {1, 0}, {0, -1}}};

void meiro(int W, int H, int c) {
    stack<pair<int, int>> s;
    s.push({W, H});
    while (!s.empty()) {
        int x = s.top().first;
        int y = s.top().second;
        s.pop();
        if (x < 0 || y < 0 || x >= 102 || y >= 102 || C[x][y] != c) continue;
        C[x][y] = -1;
        for (const auto &dir : directions) {
            s.push({x + dir.first, y + dir.second});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    while (1) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        for (auto &row : C) {
            row.fill(10);
        }
        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;
        int n;
        cin >> n;
        int c, d, x, y;
        for (int i = 0; i < n; i++) {
            cin >> c >> d >> x >> y;
            for (int j = x; j < x + 2 + 2 * (d == 0); j++) {
                for (int k = y; k < y + 2 + 2 * d; k++) {
                    C[j][k] = c;
                }
            }
        }
        meiro(xs, ys, C[xs][ys]);
        cout << (C[xg][yg] == -1 ? "OK" : "NG") << '\n';
    }
    return 0;
}
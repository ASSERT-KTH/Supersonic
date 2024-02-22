#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

int C[102][102];
const int DIRS[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void meiro(int W, int H, int c) {
    stack<pair<int, int>> s;
    s.push({W, H});
    while (!s.empty()) {
        pair<int, int> p = s.top();
        s.pop();
        if (C[p.first][p.second] != c) continue;
        C[p.first][p.second] = -1;
        for (int i = 0; i < 4; ++i) {
            int nx = p.first + DIRS[i][0];
            int ny = p.second + DIRS[i][1];
            if (nx >= 0 && nx < 102 && ny >= 0 && ny < 102)
                s.push({nx, ny});
        }
    }
}

int main() {
    while (1) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) break;

        memset(C, 10, sizeof C);

        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;
        int n;
        cin >> n;
        int c, d, x, y;
        for (int i = 0; i < n; i++) {
            cin >> c >> d >> x >> y;
            if (d == 0) {
                for (int j = x; j < x + 4; j++) {
                    for (int k = y; k < y + 2; k++) {
                        C[j][k] = c;
                    }
                }
            } else {
                for (int j = x; j < x + 2; j++) {
                    for (int k = y; k < y + 4; k++) {
                        C[j][k] = c;
                    }
                }
            }
        }
        meiro(xs, ys, C[xs][ys]);
        if (C[xg][yg] == -1) {
            cout << "OK" << endl;
            break;
        } else {
            cout << "NG" << endl;
        }
    }
    return 0;
}
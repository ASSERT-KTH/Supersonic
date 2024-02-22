#include <iostream>
#include <stack>
using namespace std;

const int MAX = 102; // Maximum size of the maze

int C[MAX][MAX];

struct Position {
    int x;
    int y;
};

void meiro(int W, int H, int c) {
    stack<Position> positions;
    positions.push({W, H});

    while (!positions.empty()) {
        Position pos = positions.top();
        positions.pop();

        int x = pos.x;
        int y = pos.y;

        if (C[x][y] != c) {
            continue;
        }

        C[x][y] = -1;

        if (x > 0) {
            positions.push({x - 1, y});
        }
        if (y < MAX - 1) {
            positions.push({x, y + 1});
        }
        if (x < MAX - 1) {
            positions.push({x + 1, y});
        }
        if (y > 0) {
            positions.push({x, y - 1});
        }
    }
}

int main() {
    while (true) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }

        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;

        int n;
        cin >> n;

        // No need to initialize C array

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
        } else {
            cout << "NG" << endl;
        }
    }

    return 0;
}
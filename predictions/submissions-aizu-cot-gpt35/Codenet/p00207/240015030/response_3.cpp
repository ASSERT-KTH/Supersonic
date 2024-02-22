#include <iostream>
using namespace std;

bool DFS(int Board[102][102], int c, int x, int y, int xg, int yg) {
    if (Board[x][y] != c) {
        return false;
    } else if (x == xg && y == yg) {
        return true;
    }
    Board[x][y] = 0;

    if (x + 1 < 102 && DFS(Board, c, x + 1, y, xg, yg)) {
        return true;
    }
    if (y + 1 < 102 && DFS(Board, c, x, y + 1, xg, yg)) {
        return true;
    }
    if (x - 1 >= 0 && DFS(Board, c, x - 1, y, xg, yg)) {
        return true;
    }
    if (y - 1 >= 0 && DFS(Board, c, x, y - 1, xg, yg)) {
        return true;
    }
    return false;
}

int main() {
    int w, h;
    cin >> w >> h;
    while (w != 0 || h != 0) {
        int Board[102][102] = {};
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> Board[j][i];
            }
        }
        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;

        int n;
        cin >> n;
        for (int t = 0; t < n; t++) {
            int c, d, x, y;
            cin >> c >> d >> x >> y;
            int wb = 2 + (!d * 2);
            int hb = 2 + (d * 2);
            for (int i = 0; i < hb; i++) {
                for (int j = 0; j < wb; j++) {
                    Board[x + j][y + i] = c;
                }
            }
        }

        if (DFS(Board, Board[xs][ys], xs, ys, xg, yg)) {
            cout << "OK" << endl;
        } else {
            cout << "NG" << endl;
        }

        cin >> w >> h;
    }
    return 0;
}
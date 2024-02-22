#include <iostream>
#include <cstring>
using namespace std;

const int MAX = 102;
int Board[MAX][MAX];
bool isOK;
int xs, ys, xg, yg;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void DFS(int c, int x, int y) {
    if (Board[x][y] != c) {
        return;
    } else if (x == xg && y == yg) {
        isOK = true;
        return;
    }
    Board[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
        DFS(c, x + dx[i], y + dy[i]);
    }
}

int main() {
    int w, h;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        isOK = false;
        memset(Board, -1, sizeof(Board));
        cin >> xs >> ys >> xg >> yg;
        int n, c, d, x, y;
        cin >> n;
        for (int t = 0; t < n; t++) {
            cin >> c >> d >> x >> y;
            int wb = 2 + (!d * 2);
            int hb = 2 + (d * 2);
            for (int i = 0; i < hb; i++) {
                for (int j = 0; j < wb; j++)
                    Board[x + j][y + i] = c;
            }
        }
        DFS(Board[xs][ys], xs, ys);
        if (isOK)
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }
    return 0;
}
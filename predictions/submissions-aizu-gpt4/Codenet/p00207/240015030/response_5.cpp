#include <iostream>
#include <vector>
#include <array>
using namespace std;

vector<vector<int>> Board(102, vector<int>(102));
bool isOK;
int xs, ys, xg, yg;

void DFS(int c, int x, int y) {
    if (x < 0 || y < 0 || x >= Board.size() || y >= Board[0].size() || Board[x][y] != c) {
        return;
    }
    if (x == xg && y == yg) {
        isOK = true;
        return;
    }
    Board[x][y] = 0;
    array<pair<int, int>, 4> directions = {{{1, 0}, {0, 1}, {-1, 0}, {0, -1}}};
    for (const auto& dir : directions) {
        DFS(c, x + dir.first, y + dir.second);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int w, h;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        isOK = false;

        for (auto &row : Board) {
            fill(row.begin(), row.end(), -1);
        }

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
        cout << (isOK ? "OK\n" : "NG\n");
    }
    return 0;
}
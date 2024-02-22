#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Node {
    int x, y;
};

vector<vector<int>> Board;
bool isOK;
int xs, ys, xg, yg;

void DFS(int c) {
    stack<Node> s;
    s.push({xs, ys});
    while (!s.empty()) {
        Node node = s.top(); s.pop();
        int x = node.x, y = node.y;
        if (Board[x][y] != c) continue;
        if (x == xg && y == yg) {
            isOK = true;
            return;
        }
        Board[x][y] = 0;

        if (x + 1 < Board.size()) s.push({x + 1, y});
        if (y + 1 < Board[0].size()) s.push({x, y + 1});
        if (x - 1 >= 0) s.push({x - 1, y});
        if (y - 1 >= 0) s.push({x, y - 1});
    }
}

int main() {
    int w, h;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        isOK = false;
        Board = vector<vector<int>>(w, vector<int>(h, -1));
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
        DFS(Board[xs][ys]);
        if (isOK)
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }
    return 0;
}
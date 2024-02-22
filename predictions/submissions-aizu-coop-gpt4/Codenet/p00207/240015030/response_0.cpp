#include <iostream>
#include <stack>
#include <vector>
using namespace std;

struct Point {
    int x, y;
    Point(int a, int b) : x(a), y(b) {}
};

int main() {
    int w, h;
    while (cin >> w >> h, w, h) {
        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;
        vector<vector<int>> board(h, vector<int>(w, -1));
        vector<vector<bool>> visited(h, vector<bool>(w, false));
        int n, c, d, x, y;
        cin >> n;
        for (int t = 0; t < n; t++) {
            cin >> c >> d >> x >> y;
            int wb = 2 + (!d * 2);
            int hb = 2 + (d * 2);
            for (int i = 0; i < hb; i++) {
                for (int j = 0; j < wb; j++) {
                    board[y + i][x + j] = c;
                }
            }
        }
        stack<Point> s;
        s.push(Point(xs, ys));
        bool isOK = false;
        while (!s.empty() && !isOK) {
            Point p = s.top();
            s.pop();
            int x = p.x;
            int y = p.y;
            if (x == xg && y == yg) {
                isOK = true;
                break;
            }
            const int dx[4] = {1, 0, -1, 0};
            const int dy[4] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < w && ny >= 0 && ny < h && !visited[ny][nx] && board[ny][nx] == board[ys][xs]) {
                    s.push(Point(nx, ny));
                    visited[ny][nx] = true;
                }
            }
        }
        cout << (isOK ? "OK" : "NG") << endl;
    }
    return 0;
}
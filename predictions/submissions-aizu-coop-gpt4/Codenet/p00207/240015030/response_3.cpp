#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct Point {
    int x, y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

void DFS(vector<vector<int>>& Board, int xs, int ys, int xg, int yg) {
    stack<Point> st;
    st.push(Point(xs, ys));
    int c = Board[xs][ys];
    while (!st.empty()) {
        Point p = st.top();
        st.pop();
        int x = p.x, y = p.y;
        if (x < 0 || y < 0 || x >= Board.size() || y >= Board[0].size() || Board[x][y] != c) {
            continue;
        }
        Board[x][y] = 0;
        if (x == xg && y == yg) {
            cout << "OK" << endl;
            return;
        }
        st.push(Point(x + 1, y));
        st.push(Point(x, y + 1));
        st.push(Point(x - 1, y));
        st.push(Point(x, y - 1));
    }
    cout << "NG" << endl;
}

int main() {
    int w, h;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        vector<vector<int>> Board(h, vector<int>(w, -1));
        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;
        int n, c, d, x, y;
        cin >> n;
        for (int t = 0; t < n; t++) {
            cin >> c >> d >> x >> y;
            int wb = 2 + (!d * 2);
            int hb = 2 + (d * 2);
            for (int i = 0; i < hb; i++) {
                for (int j = 0; j < wb; j++)
                    Board[y + i][x + j] = c;
            }
        }
        DFS(Board, xs, ys, xg, yg);
    }
    return 0;
}
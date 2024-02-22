#include <cstdio>
#include <stack>
using namespace std;

int C[102][102];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

struct Point {
    int x;
    int y;
    Point(int _x, int _y) : x(_x), y(_y) {}
};

void meiro(int W, int H, int c) {
    stack<Point> s;
    s.push(Point(W, H));
    while (!s.empty()) {
        Point p = s.top(); s.pop();
        if (p.x < 0 || p.x >= 102 || p.y < 0 || p.y >= 102 || C[p.x][p.y] != c) continue;
        C[p.x][p.y] = -1;
        for (int i = 0; i < 4; i++) {
            s.push(Point(p.x + dx[i], p.y + dy[i]));
        }
    }
}

int main() {
    while (1) {
        int w, h;
        scanf("%d %d", &w, &h);
        if (w == 0 && h == 0) {
            break;
        }
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++) {
                C[i][j] = 10;
            }
        }
        int xs, ys, xg, yg;
        scanf("%d %d %d %d", &xs, &ys, &xg, &yg);
        int n;
        scanf("%d", &n);
        int c, d, x, y;
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d %d", &c, &d, &x, &y);
            int e = (d == 0) ? 4 : 2;
            int f = (d == 0) ? 2 : 4;
            for (int j = x; j < x + e; j++) {
                for (int k = y; k < y + f; k++) {
                    C[j][k] = c;
                }
            }
        }
        meiro(xs, ys, C[xs][ys]);
        if (C[xg][yg] == -1) {
            printf("OK\n");
        } else {
            printf("NG\n");
        }
    }
    return 0;
}
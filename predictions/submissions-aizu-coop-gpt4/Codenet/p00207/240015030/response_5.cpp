#include <iostream>
#include <stack>
using namespace std;

int Board[102][102];
bool visited[102][102];
int xs, ys, xg, yg;

struct Point
{
    int x;
    int y;
};

void DFS(int c) {
    stack<Point> s;
    s.push({xs, ys});
    
    while(!s.empty()) {
        Point p = s.top();
        s.pop();

        if(p.x < 0 || p.y < 0 || p.x >= 102 || p.y >= 102)
            continue;
        if(Board[p.x][p.y] != c || visited[p.x][p.y])
            continue;

        visited[p.x][p.y] = true;
        if (p.x == xg && p.y == yg) {
            cout << "OK" << endl;
            return;
        }

        s.push({p.x + 1, p.y});
        s.push({p.x, p.y + 1});
        s.push({p.x - 1, p.y});
        s.push({p.x, p.y - 1});
    }
    cout << "NG" << endl;
}

int main() {
    int w, h;
    while (true) {
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;
        for (int i = 0; i < 102; i++) {
            for (int j = 0; j < 102; j++)
                Board[j][i] = visited[j][i] = -1;
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
        DFS(Board[xs][ys]);
    }
    return 0;
}
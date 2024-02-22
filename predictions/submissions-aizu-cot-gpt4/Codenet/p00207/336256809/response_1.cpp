#include <iostream>
#include <stack>
using namespace std;

typedef pair<int, int> pii;

int C[102][102];

void meiro(int W, int H, int c) {
    stack<pii> dfs_stack;
    dfs_stack.push({W, H});

    while (!dfs_stack.empty()) {
        pii top = dfs_stack.top();
        dfs_stack.pop();
        
        if (top.first < 0 || top.first >= 102 || top.second < 0 || top.second >= 102 || C[top.first][top.second] != c) {
            continue;
        }

        C[top.first][top.second] = -1;
        dfs_stack.push({top.first - 1, top.second});
        dfs_stack.push({top.first, top.second + 1});
        dfs_stack.push({top.first + 1, top.second});
        dfs_stack.push({top.first, top.second - 1});
    }
}

int main() {
    while (1) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0) {
            break;
        }
        
        for (int i = 0; i < w; i++) {
            for (int j = 0; j < h; j++) {
                C[i][j] = 10;
            }
        }
        
        int xs, ys, xg, yg, n;
        cin >> xs >> ys >> xg >> yg >> n;
        
        for (int i = 0; i < n; i++) {
            int c, d, x, y;
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
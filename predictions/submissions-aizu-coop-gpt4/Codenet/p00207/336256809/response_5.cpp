#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

void meiro(vector<vector<int>>& C, int W, int H, int c) {
    stack<pii> s;
    s.push({W, H});

    while (!s.empty()) {
        pii p = s.top(); s.pop();
        int W = p.first, H = p.second;

        if (C[W][H] != c)
            continue;

        C[W][H] = -1;

        s.push({W - 1, H});
        s.push({W, H + 1});
        s.push({W + 1, H});
        s.push({W, H - 1});
    }
}

int main() {
    while (1) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        vector<vector<int>> C(w + 2, vector<int>(h + 2, 10));

        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;
        int n;
        cin >> n;
        int c, d, x, y;
        for (int i = 0; i < n; i++) {
            cin >> c >> d >> x >> y;
            for (int j = x; j < (d == 0 ? x + 4 : x + 2); j++) {
                fill(C[j].begin() + y, C[j].begin() + y + (d == 0 ? 2 : 4), c);
            }
        }

        meiro(C, xs, ys, C[xs][ys]);
        if (C[xg][yg] == -1)
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }
    return 0;
}
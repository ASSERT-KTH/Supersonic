#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int C[102][102];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void meiro(int W, int H, int c) {
    stack<pair<int, int>> st;
    st.push({W, H});

    while (!st.empty()) {
        auto [x, y] = st.top();
        st.pop();
        if (C[x][y] != c)
            continue;

        C[x][y] = -1;
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx >= 0 && nx < 102 && ny >= 0 && ny < 102)
                st.push({nx, ny});
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (1) {
        int w, h;
        cin >> w >> h;
        if (w == 0 && h == 0)
            break;

        memset(C, 10, sizeof(C));

        int xs, ys, xg, yg;
        cin >> xs >> ys >> xg >> yg;
        int n;
        cin >> n;
        int c, d, x, y;
        for (int i = 0; i < n; i++) {
            cin >> c >> d >> x >> y;
            if (d == 0) {
                for (int j = x; j < x + 4; j++)
                    for (int k = y; k < y + 2; k++)
                        C[j][k] = c;
            } else {
                for (int j = x; j < x + 2; j++)
                    for (int k = y; k < y + 4; k++)
                        C[j][k] = c;
            }
        }

        meiro(xs, ys, C[xs][ys]);
        if (C[xg][yg] == -1)
            cout << "OK" << endl;
        else
            cout << "NG" << endl;
    }
    return 0;
}
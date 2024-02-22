#include <iostream>
#include <queue>
using namespace std;

int w, h;
string mp[2][51];
bool visited[51][51];
int lx, ly, rx, ry;
int hasPercentL, hasPercentR;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bfs() {
    queue<pair<int, int>> Q;
    Q.push({lx, ly});

    while (!Q.empty()) {
        pair<int, int> t = Q.front();
        Q.pop();
        int cnt = (mp[0][t.second][t.first] == '%') + (mp[1][ry][rx] == '%');

        if (cnt == 2)
            return true;

        if (visited[t.first][t.second] || cnt == 1)
            continue;

        visited[t.first][t.second] = true;

        for (int i = 0; i < 4; i++) {
            int flg = 0;
            int nlx = t.first + dx[i], nly = t.second + dy[i];
            int nrx = rx - dx[i], nry = ry + dy[i];

            if (nlx < 0 || nly < 0 || nlx >= w || nly >= h || mp[0][nly][nlx] == '#') {
                nlx = t.first;
                nly = t.second;
                flg++;
            }

            if (nrx < 0 || nry < 0 || nrx >= w || nry >= h || mp[1][nry][nrx] == '#') {
                nrx = rx;
                nry = ry;
                flg++;
            }

            if (flg == 2)
                continue;

            Q.push({nlx, nly});
        }
    }

    return false;
}

int main() {
    while (1) {
        cin >> w >> h;

        if (!w && !h)
            break;

        if (w < 1 || w > 50 || h < 1 || h > 50) {
            cerr << "Invalid input dimensions" << endl;
            return 1;
        }

        for (int i = 0; i < h; i++)
            cin >> mp[0][i] >> mp[1][i];

        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (mp[0][i][j] == 'L') {
                    lx = j;
                    ly = i;
                }
                if (mp[1][i][j] == 'R') {
                    rx = j;
                    ry = i;
                }
            }
        }

        hasPercentL = (mp[0][ly][lx] == '%');
        hasPercentR = (mp[1][ry][rx] == '%');

        memset(visited, false, sizeof(visited));

        if (bfs())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}
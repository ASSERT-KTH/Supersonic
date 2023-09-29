#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

struct aa {
    int x, y, turn;
};

struct bb {
    int kx, ky, opway, turn;
};

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};

int memo[60][60][4];

class Compare {
public:
    bool operator()(const bb &l, const bb &r) { return l.turn > r.turn; }
};

int getdis(vector<vector<int>> &field, int fx, int fy, int gx, int gy) {
    vector<vector<int>> memo(field.size(), vector<int>(field[0].size(), INT_MAX));
    queue<aa> que;
    que.push({fx, fy, 0});
    while (!que.empty()) {
        aa atop = que.front();
        que.pop();
        if (atop.x == gx && atop.y == gy) return atop.turn;
        for (int i = 0; i < 4; ++i) {
            int nextx = atop.x + dx[i];
            int nexty = atop.y + dy[i];
            if (nextx >= 0 && nexty >= 0 && nextx < field[0].size() && nexty < field.size() && !field[nexty][nextx])
                if (atop.turn + 1 < memo[nexty][nextx]) {
                    memo[nexty][nextx] = atop.turn + 1;
                    que.push({nextx, nexty, atop.turn + 1});
                }
        }
    }
    return INT_MAX;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        for (auto &i : memo)
            for (auto &j : i)
                for (auto &k : j)
                    k = INT_MAX;
        int H, W;
        cin >> H >> W;
        if (!H) break;
        vector<vector<int>> field(H + 2, vector<int>(W + 2, true));
        int kx = INT_MAX, ky = INT_MAX, ox[2], oy[2], num = 0;
        for (int i = 0; i < H; ++i) {
            string st;
            cin >> st;
            for (int j = 0; j < W; ++j) {
                if (st[j] == 'X') {
                    kx = min(kx, j + 1);
                    ky = min(ky, i + 1);
                }
                field[i + 1][j + 1] = (st[j] == 'X');
                if (st[j] == '.') {
                    ox[num] = j + 1;
                    oy[num++] = i + 1;
                }
            }
        }
        if (kx == 1 && ky == 1) {
            cout << 0 << '\n';
            continue;
        }
        priority_queue<bb, vector<bb>, Compare> que;
        for (int way = 0; way < 4; ++way) {
            int amin = INT_MAX;
            bool ok = true;
            for (int op = 0; op < 2; ++op) {
                int atime = 0;
                for (int lu = 0; lu < 2; ++lu) {
                    int fx = ox[op ^ lu], fy = oy[op ^ lu];
                    int gx = kx + dx2[way], gy = ky + dy2[way];
                    if (lu) {
                        gx += dx[(way + 1) % 4];
                        gy += dy[(way + 1) % 4];
                    }
                    if (gx<0 || gy<0 || gx>W || gy>H || field[gy][gx])
                        ok = false;
                    else
                        atime += getdis(field, fx, fy, gx, gy);
                }
                amin = min(amin, atime);
            }
            if (ok) {
                memo[kx][ky][way] = amin;
                que.push({kx, ky, way, amin});
            }
        }
        int ans = -1;
        while (!que.empty()) {
            bb atop = que.top();
            que.pop();
            if (atop.kx == 1 && atop.ky == 1) {
                ans = atop.turn;
                break;
            }
            for (int tway = 0; tway < 4; ++tway) {
                if (atop.opway == tway) continue;
                int amin = INT_MAX;
                bool ok = true;
                for (int op = 0; op < 2; ++op) {
                    int atime = 0;
                    for (int lu = 0; lu < 2; ++lu) {
                        int fx = atop.kx + dx2[atop.opway], fy = atop.ky + dy2[atop.opway];
                        int gx = atop.kx + dx2[tway], gy = atop.ky + dy2[tway];
                        if (lu) {
                            gx += dx[(tway + 1) % 4];
                            gy += dy[(tway + 1) % 4];
                        }
                        if (op ^ lu) {
                            fx += dx[(atop.opway + 1) % 4];
                            fy += dy[(atop.opway + 1) % 4];
                        }
                        if (fx<0 || fy<0 || gx<0 || gy<0 || gx>W || gy>H || field[gy][gx])
                            ok = false;
                        else
                            atime += getdis(field, fx, fy, gx, gy);
                    }
                    amin = min(amin, atime);
                }
                if (ok && memo[atop.kx][atop.ky][tway] > atop.turn + amin) {
                    memo[atop.kx][atop.ky][tway] = atop.turn + amin;
                    que.push({atop.kx, atop.ky, tway, atop.turn + amin});
                }
            }
            int nkx = atop.kx + dx[atop.opway], nky = atop.ky + dy[atop.opway];
            int nway = (atop.opway + 2) % 4;
            if (nky>=0 && nkx>=0 && nky<H && nkx<W && memo[nkx][nky][nway] > atop.turn + 1) {
                memo[nkx][nky][nway] = atop.turn + 1;
                que.push({nkx, nky, nway, atop.turn + 1});
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
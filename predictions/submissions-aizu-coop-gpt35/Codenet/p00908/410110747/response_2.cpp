#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};

int getdis(const vector<int>& field, int W, int fx, int fy, int gx, int gy) {
    int ans = 999999;
    queue<pair<int, int>> que;
    vector<int> memo(field.size(), 999999);
    que.push(make_pair(fx, fy));
    memo[fy * (W + 2) + fx] = 0;
    while (!que.empty()) {
        pair<int, int> atop = que.front();
        que.pop();
        int x = atop.first;
        int y = atop.second;
        if (x == gx && y == gy) {
            ans = memo[y * (W + 2) + x];
            break;
        }
        for (int i = 0; i < 4; ++i) {
            int nextx = x + dx[i];
            int nexty = y + dy[i];
            if (!field[nexty * (W + 2) + nextx]) {
                if (memo[nexty * (W + 2) + nextx] > memo[y * (W + 2) + x] + 1) {
                    memo[nexty * (W + 2) + nextx] = memo[y * (W + 2) + x] + 1;
                    que.push(make_pair(nextx, nexty));
                }
            }
        }
    }
    return ans;
}

class State {
public:
    int kx;
    int ky;
    int opway;
    int turn;

    State(int kx, int ky, int opway, int turn) : kx(kx), ky(ky), opway(opway), turn(turn) {}

    bool operator<(const State& other) const {
        return turn > other.turn;
    }
};

int main() {
    while (1) {
        int H, W;
        cin >> H >> W;
        if (!H)
            break;
        vector<int> field((H + 2) * (W + 2), true);
        vector<vector<vector<int>>> memo2(60, vector<vector<int>>(60, vector<int>(4, 999999)));
        vector<State> que;
        
        int kx = 99, ky = 99;
        int ox[2];
        int oy[2];
        int num = 0;
        for (int i = 0; i < H; i += 2) {
            string st1, st2;
            cin >> st1 >> st2;
            for (int j = 0; j < W; j += 2) {
                if (st1[j] == 'X' || st2[j] == 'X') {
                    kx = min(kx, j + 1);
                    ky = min(ky, i + 1);
                    field[(i + 1) * (W + 2) + j + 1] = false;
                } else if (st1[j] == 'o' || st2[j] == 'o') {
                    field[(i + 1) * (W + 2) + j + 1] = false;
                } else if (st1[j] == '.' || st2[j] == '.') {
                    field[(i + 1) * (W + 2) + j + 1] = false;
                    ox[num] = j + 1;
                    oy[num] = i + 1;
                    num++;
                }
            }
        }
        
        if (kx == 1 && ky == 1) {
            cout << 0 << endl;
            continue;
        }
        
        for (int way = 0; way < 4; ++way) {
            int amin = 999999;
            bool ok = true;
            for (int op = 0; op < 2; ++op) {
                int atime = 0;
                for (int lu = 0; lu < 2; ++lu) {
                    const int fx = ox[op ^ lu];
                    const int fy = oy[op ^ lu];
                    int gx = kx + dx2[way];
                    int gy = ky + dy2[way];
                    if (lu == 1) {
                        gx += dx[(way + 1) % 4];
                        gy += dy[(way + 1) % 4];
                    }
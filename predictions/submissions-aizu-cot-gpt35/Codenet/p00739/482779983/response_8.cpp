#include <iostream>
#include <array>
#include <unordered_set>

constexpr int dx[] = {0, 1, 0, -1};
constexpr int dy[] = {-1, 0, 1, 0};

int w, h;
std::array<int, 20> tatu_x, tatu_y, kazu_x, kazu_y;
std::array<std::array<int, 12>, 12> field;
std::array<int, 36> cx, cy;
int csize;
std::unordered_set<long long> visited[20][4][2];

bool inside(int x, int y) {
    return x >= 0 && x < w && y >= 0 && y < h;
}

bool backtrack(int cnt, long long kS, int init_dir, int f) {
    if (visited[cnt][init_dir][f].count(kS))
        return false;
    if (csize / 2 == cnt)
        return true;
    for (int i = 0; i < cnt; i++) {
        for (int k = 0; k < 4; k++) {
            int tx = tatu_x[i] + dx[k];
            int ty = tatu_y[i] + dy[k];
            if (!inside(tx, ty) || field[ty][tx] == 0)
                continue;
            int ttx = kazu_x[i] + dx[(k + init_dir + (f ? 2 : 0)) % 4];
            int tty = kazu_y[i] + dy[(k + init_dir) % 4];
            if ((tx == ttx && ty == tty) || !inside(ttx, tty) || field[tty][ttx] == 0)
                continue;
            field[ty][tx] = 0;
            tatu_x[cnt] = tx, tatu_y[cnt] = ty;
            field[tty][ttx] = 0;
            kazu_x[cnt] = ttx, kazu_y[cnt] = tty;
            if (backtrack(cnt + 1, kS | (1LL << (ttx + tty * w)), init_dir, f))
                return true;
            field[tty][ttx] = 1;
            field[ty][tx] = 1;
        }
    }
    visited[cnt][init_dir][f].insert(kS);
    return false;
}

bool solve() {
    if (csize % 2)
        return false;
    tatu_x[0] = cx[0], tatu_y[0] = cy[0];
    field[cy[0]][cx[0]] = 0;
    for (int j = 1; j < csize; j++) {
        kazu_x[0] = cx[j], kazu_y[0] = cy[j];
        field[cy[j]][cx[j]] = 0;
        for (int k = 0; k < 4; k++) {
            if (backtrack(1, 1LL << (cx[j] + cy[j] * w), k, 0))
                return true;
            if (backtrack(1, 1LL << (cx[j] + cy[j] * w), k, 1))
                return true;
        }
        field[cy[j]][cx[j]] = 1;
    }
    field[cy[0]][cx[0]] = 1;
    return false;
}

int main() {
    while (std::cin >> w >> h, w | h) {
        for (int i = 0; i < 20; i++)
            for (int j = 0; j < 4; j++)
                for (int k = 0; k < 2; k++)
                    visited[i][j][k].clear();
        csize = 0;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                std::cin >> field[i][j];
                if (field[i][j] == 1) {
                    cx[csize] = j, cy[csize] = i;
                    csize++;
                }
            }
        }
        std::cout << (solve() ? "YES" : "NO") << std::endl;
    }
    return 0;
}
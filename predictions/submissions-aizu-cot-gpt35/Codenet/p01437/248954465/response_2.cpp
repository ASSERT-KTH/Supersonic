#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const string tmp = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};

void dfs(int x, int y, int v, long long step, int H, int W, const vector<string>& C, vector<vector<vector<long long>>>& nxt) {
    int nx, ny, nv;
    while (step > 0) {
        nx = x + vx[v];
        ny = y + vy[v];
        nv = (v + 1) % 4;

        if (step == 1) {
            cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
            return;
        } else if (nx >= 0 && ny >= 0 && nx < W && ny < H && C[ny][nx] != '#') {
            long long loop = (nxt[nx][ny][v] != -1) ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
            nxt[nx][ny][v] = nxt[x][y][v] + 1;
            step = (step - 1) % loop;
            x = nx;
            y = ny;
        } else {
            nxt[x][y][nv] = nxt[x][y][v];
            v = nv;
            step--;
        }
    }
}

int main() {
    int H, W;
    long long L;
    while (scanf("%d %d %lld", &H, &W, &L), H) {
        vector<string> C(H);
        vector<vector<vector<long long>>> nxt(W, vector<vector<long long>>(H, vector<long long>(4, -1)));
        int sx, sy, sv;
        for (int i = 0; i < H; i++) {
            cin >> C[i];
            for (int j = 0; j < W; j++) {
                int p;
                switch (C[i][j]) {
                    case 'N':
                        p = 0;
                        break;
                    case 'E':
                        p = 1;
                        break;
                    case 'S':
                        p = 2;
                        break;
                    case 'W':
                        p = 3;
                        break;
                }
                if (p != -1)
                    sx = j, sy = i, sv = p;
            }
        }
        nxt[sx][sy][sv] = 0;
        dfs(sx, sy, sv, L, H, W, C, nxt);
    }
    return 0;
}
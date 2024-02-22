#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;
typedef long long int64;
const string tmp = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
int H, W;
int64 L;
vector<string> C(100);
int sx, sy, sv;
int64 nxt[100][100][4];
map<char, int> tmpMap;

void initTmpMap() {
    for(int i = 0; i < tmp.length(); i++) {
        tmpMap[tmp[i]] = i;
    }
}

void dfs() {
    int64 step = L;
    int x = sx, y = sy, v = sv;
    while (step > 0) {
        int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
        if (step == 0) {
            cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
            break;
        } else if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
            int64 loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
            nxt[nx][ny][v] = nxt[x][y][v] + 1;
            step = (step - 1) % loop;
            x = nx; y = ny;
        } else {
            nxt[x][y][nv] = nxt[x][y][v];
            step--;
            v = nv;
        }
    }
}

int main() {
    initTmpMap();
    while (cin >> H >> W >> L, H) {
        for (int i = 0; i < H; i++) {
           for (int j = 0; j < W; j++) {
               for (int k = 0; k < 4; k++) {
                   nxt[i][j][k] = -1;
               }
           }
        }
        for (int i = 0; i < H; i++) {
            cin >> C[i];
            for (int j = 0; j < W; j++) {
                if (tmpMap.count(C[i][j])) {
                    sx = j, sy = i, sv = tmpMap[C[i][j]];
                }
            }
        }
        nxt[sx][sy][sv] = 0;
        dfs();
    }
}
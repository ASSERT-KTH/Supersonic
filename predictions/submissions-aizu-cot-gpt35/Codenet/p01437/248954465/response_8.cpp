#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const string tmp = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};

void dfs(vector<vector<vector<int>>>& nxt, vector<string>& C, int x, int y, int v, int64_t step) {
    int H = C.size();
    int W = C[0].size();
    
    while (step > 0) {
        int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
        if (step == 1) {
            cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
            return;
        } else if (0 <= nx && nx < W && 0 <= ny && ny < H && C[ny][nx] != '#') {
            int64_t loop = ~nxt[nx][ny][v] ? nxt[x][y][v] - nxt[nx][ny][v] + 1 : step;
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
    int64_t L;
    
    while (cin >> H >> W >> L, H) {
        vector<vector<vector<int>>> nxt(W, vector<vector<int>>(H, vector<int>(4, -1)));
        vector<string> C(H);
        int sx, sy, sv;
        
        for (int i = 0; i < H; i++) {
            cin >> C[i];
            for (int j = 0; j < W; j++) {
                int p = tmp.find(C[i][j]);
                if (p != string::npos) {
                    sx = j;
                    sy = i;
                    sv = p;
                }
            }
        }
        
        nxt[sx][sy][sv] = 0;
        dfs(nxt, C, sx, sy, sv, L);
    }
}
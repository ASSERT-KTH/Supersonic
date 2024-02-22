#include <bits/stdc++.h>
using namespace std;
typedef long long int64;
const string tmp = "NESW";
const int vy[] = {-1, 0, 1, 0}, vx[] = {0, 1, 0, -1};
int H, W;
int64 L;
string C[100];
int sx, sy, sv;
unordered_map<int64, int64> nxt;

void simulate(int x, int y, int v, int64 step) {
  while(step > 0) {
    int nx = x + vx[v], ny = y + vy[v], nv = (v + 1) % 4;
    if (0 <= nx && 0 <= ny && nx < W && ny < H && C[ny][nx] != '#') {
      int64 key = nx * 10000 + ny * 100 + v;
      if(nxt.count(key)) {
        int64 loop = nxt[x*10000 + y*100 + v] - nxt[key] + 1;
        step = (step - 1) % loop;
      } else {
        nxt[key] = nxt[x*10000 + y*100 + v] + 1;
        step--;
      }
      x = nx; y = ny;
    } else {
      v = nv;
    }
  }
  cout << y + 1 << " " << x + 1 << " " << tmp[v] << endl;
}

int main() {
  while (cin >> H >> W >> L, H) {
    nxt.clear();
    for (int i = 0; i < H; i++) {
      cin >> C[i];
      for (int j = 0; j < W; j++) {
        int p = tmp.find(C[i][j]);
        if (p != string::npos)
          sx = j, sy = i, sv = p;
      }
    }
    nxt[sx*10000 + sy*100 + sv] = 0;
    simulate(sx, sy, sv, L);
  }
}
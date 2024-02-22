#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};

int getdis(const vector<int> &field, const int fx, const int fy,
           const int gx, const int gy, const int width) {
  int ans = 999999;
  queue<pair<int, int>> que;
  vector<int> memo(field.size(), 999999);
  que.push({fx, fy});
  memo[fx * width + fy] = 0;
  while (!que.empty()) {
    auto atop = que.front();
    que.pop();
    int x = atop.first;
    int y = atop.second;
    if (x == gx && y == gy) {
      ans = memo[x * width + y];
      break;
    }
    for (int i = 0; i < 4; ++i) {
      int nextx = x + dx[i];
      int nexty = y + dy[i];
      if (!field[nextx * width + nexty]) {
        if (memo[nextx * width + nexty] > memo[x * width + y] + 1) {
          memo[nextx * width + nexty] = memo[x * width + y] + 1;
          que.push({nextx, nexty});
        }
      }
    }
  }
  return ans;
}

int main() {
  while (1) {
    int H, W;
    cin >> H >> W;
    if (!H)
      break;
    vector<int> field((H + 2) * (W + 2), true);
    {
      int kx = 99, ky = 99;
      int ox[2];
      int oy[2];
      int num = 0;
      for (int i = 0; i < H; ++i) {
        string st;
        cin >> st;
        for (int j = 0; j < W; ++j) {
          if (st[j] == 'X') {
            kx = min(kx, j + 1);
            ky = min(ky, i + 1);
            field[(i + 1) * (W + 2) + (j + 1)] = false;
          } else if (st[j] == 'o') {
            field[(i + 1) * (W + 2) + (j + 1)] = false;
          } else if (st[j] == '.') {
            field[(i + 1) * (W + 2) + (j + 1)] = false;
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
      vector<int> memo2((W + 2) * (H + 2) * 4, 999999);
      vector<pair<int, int>> que;
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
            if (field[gy * (W + 2) + gx])
              ok = false;
            for (int ax = 0; ax < 2; ++ax) {
              for (int ay = 0; ay < 2; ++ay) {
                field[(ky + ay) * (W + 2) + (kx + ax)] = true;
              }
            }
            atime += getdis(field, fx, fy, gx, gy, W + 2);
            for (int ax = 0; ax < 2; ++ax) {
              for (int ay = 0; ay < 2; ++ay) {
                field[(ky + ay) * (W + 2) + (kx + ax)] = false;
              }
            }
          }
          amin = min(amin, atime);
        }
        if (!ok)
          continue;
        else {
          memo2[kx * (W + 2) * 4 + ky * 4 + way] = amin;
          que.push_back({kx, ky});
        }
      }
      int ans = -1;
      int qpos = 0;
      while (qpos < que.size()) {
        auto atop = que[qpos++];
        const int fkx = atop.first;
        const int fky = atop.second;
        for (int tway = 0; tway < 4; ++tway) {
          int fway = memo2[fkx * (W + 2) * 4 + fky * 4 + tway];
          if (fway == 999999)
            continue;
          for (int op = 0; op < 2; ++op) {
            int atime = 0;
            for (int lu = 0; lu < 2; ++lu) {
              int fx = fkx + dx2[fway];
              int fy = fky + dy2[fway];
              int gx = fkx + dx2[tway];
              int gy = fky + dy2[tway];
              if (lu == 1) {
                gx += dx[(tway + 1) % 4];
                gy += dy[(tway + 1) % 4];
              }
              if (op ^ lu) {
                fx += dx[(fway + 1) % 4];
                fy += dy[(fway + 1) % 4];
              }
              if (field[gy * (W + 2) + gx])
                continue;
              for (int ax = 0; ax < 2; ++ax) {
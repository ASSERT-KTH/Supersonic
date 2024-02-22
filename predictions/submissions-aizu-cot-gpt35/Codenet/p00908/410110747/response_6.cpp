#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};

int getdis(const vector<vector<int>>& field, const int fx, const int fy,
           const int gx, const int gy) {
  int ans = 999999;
  queue<pair<int, int>> que;
  que.push({fx, fy});
  while (!que.empty()) {
    pair<int, int> atop = que.front();
    que.pop();
    if (atop.first == gx && atop.second == gy) {
      ans = abs(fx - gx) + abs(fy - gy);
      break;
    }
    for (int i = 0; i < 4; ++i) {
      const int nextx = atop.first + dx[i];
      const int nexty = atop.second + dy[i];
      if (!field[nexty][nextx]) {
        field[nexty][nextx] = true;
        que.push({nextx, nexty});
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
    vector<vector<int>> field(H + 2, vector<int>(W + 2, true));
    priority_queue<pair<int, pair<int, pair<int, int>>>> que;
    int kx = 99, ky = 99;
    int ox[2], oy[2];
    int num = 0;
    for (int i = 0; i < H; ++i) {
      string st;
      cin >> st;
      for (int j = 0; j < W; ++j) {
        if (st[j] == 'X') {
          kx = min(kx, j + 1);
          ky = min(ky, i + 1);
        } else if (st[j] == 'o') {
          field[i + 1][j + 1] = false;
        } else if (st[j] == '.') {
          field[i + 1][j + 1] = false;
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
          if (field[gy][gx])
            ok = false;
          atime += getdis(field, fx, fy, gx, gy);
        }
        amin = min(amin, atime);
      }
      if (!ok)
        continue;
      else {
        que.push({-amin, {kx, {ky, way}}});
      }
    }
    int ans = -1;
    while (!que.empty()) {
      int fturn = -que.top().first;
      int fkx = que.top().second.first;
      int fky = que.top().second.second.first;
      int fway = que.top().second.second.second;
      que.pop();
      if (fkx == 1 && fky == 1) {
        ans = fturn;
        break;
      }
      for (int tway = 0; tway < 4; ++tway) {
        if (fway == tway)
          continue;
        int amin = 999999;
        bool ok = true;
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
            if (field[gy][gx])
              ok = false;
            atime += getdis(field, fx, fy, gx, gy);
          }
          amin = min(amin, atime);
        }
        if (!ok)
          continue;
        else {
          if (memo2[fkx][fky][tway] > fturn + amin) {
            memo2[fkx][fky][tway] = fturn + amin;
            que.push({-(fturn + amin), {fkx, {fky, tway}}});
          }
        }
      }
      {
        const int nkx = fkx + dx[fway];
        const int nky = fky + dy[fway];
        const int nway = (fway + 2) % 4;
        if (memo2[nkx][nky][nway] > fturn + 1) {
          memo2[nkx][nky][nway] = fturn + 1;
          que.push({-(fturn + 1), {nkx, {nky, nway}}});
        }
      }
    }
    cout << ans << endl;
  }
  return 0;
}
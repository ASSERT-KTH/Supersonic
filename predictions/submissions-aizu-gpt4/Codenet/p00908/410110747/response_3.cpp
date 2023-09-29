#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
using namespace std;

constexpr int INF = 1e9;
constexpr int dx[] = {-1, 0, 1, 0};
constexpr int dy[] = {0, 1, 0, -1};
constexpr int dx2[] = {-1, 0, 2, 1};
constexpr int dy2[] = {0, 2, 1, -1};

struct AA {
  int x, y, turn;
};

int getdis(const vector<vector<int>>& field, int fx, int fy, int gx, int gy) {
  int ans = INF;
  queue<AA> que;
  vector<vector<int>> memo(field.size(), vector<int>(field[0].size(), INF));
  que.push({fx, fy, 0});

  while (!que.empty()) {
    AA atop = que.front();
    que.pop();

    if (atop.x == gx && atop.y == gy) {
      ans = atop.turn;
      break;
    }

    for (int i = 0; i < 4; ++i) {
      int nextx = atop.x + dx[i];
      int nexty = atop.y + dy[i];

      if (!field[nexty][nextx] && atop.turn + 1 < memo[nexty][nextx]) {
        memo[nexty][nextx] = atop.turn + 1;
        que.push({nextx, nexty, atop.turn + 1});
      }
    }
  }

  return ans;
}

struct BB {
  int kx, ky, opway, turn;
};

class Compare {
public:
  bool operator()(const BB& l, const BB& r) { return l.turn > r.turn; }
};

int memo2[60][60][4];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  while (true) {
    fill_n(**memo2, sizeof(memo2) / sizeof(memo2[0][0][0]), INF);

    int H, W;
    cin >> H >> W;

    if (H == 0) break;

    vector<vector<int>> field(H + 2, vector<int>(W + 2, true));
    priority_queue<BB, vector<BB>, Compare> que;
    int kx = 99, ky = 99;
    vector<int> ox(2), oy(2);
    int num = 0;

    for (int i = 0; i < H; ++i) {
      string st;
      cin >> st;

      for (int j = 0; j < W; ++j) {
        if (st[j] == 'X') {
          kx = min(kx, j + 1);
          ky = min(ky, i + 1);
          field[i + 1][j + 1] = false;
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
      cout << 0 << '\n';
      continue;
    }

    for (int way = 0; way < 4; ++way) {
      int amin = INF;
      bool ok = true;

      for (int op = 0; op < 2; ++op) {
        int atime = 0;

        for (int lu = 0; lu < 2; ++lu) {
          int fx = ox[op ^ lu];
          int fy = oy[op ^ lu];
          int gx = kx + dx2[way];
          int gy = ky + dy2[way];

          if (lu == 1) {
            gx += dx[(way + 1) % 4];
            gy += dy[(way + 1) % 4];
          }

          if (field[gy][gx]) ok = false;
          fill_n(*field.begin()+ky, 2, vector<int>(W+2, true));
          atime += getdis(field, fx, fy, gx, gy);
          fill_n(*field.begin()+ky, 2, vector<int>(W+2, false));
        }

        amin = min(amin, atime);
      }

      if (ok) {
        memo2[kx][ky][way] = amin;
        que.push({kx, ky, way, amin});
      }
    }

    int ans = -1;

    while (!que.empty()) {
      BB atop = que.top();
      que.pop();

      if (atop.kx == 1 && atop.ky == 1) {
        ans = atop.turn;
        break;
      }

      for (int tway = 0; tway < 4; ++tway) {
        if (atop.opway == tway) continue;

        int amin = INF;
        bool ok = true;

        for (int op = 0; op < 2; ++op) {
          int atime = 0;

          for (int lu = 0; lu < 2; ++lu) {
            int fx = atop.kx + dx2[atop.opway];
            int fy = atop.ky + dy2[atop.opway];
            int gx = atop.kx + dx2[tway];
            int gy = atop.ky + dy2[tway];

            if (lu == 1) {
              gx += dx[(tway + 1) % 4];
              gy += dy[(tway + 1) % 4];
            }

            if (op ^ lu) {
              fx += dx[(atop.opway + 1) % 4];
              fy += dy[(atop.opway + 1) % 4];
            }

            if (field[gy][gx]) ok = false;
            fill_n(*field.begin()+atop.ky, 2, vector<int>(W+2, true));
            atime += getdis(field, fx, fy, gx, gy);
            fill_n(*field.begin()+atop.ky, 2, vector<int>(W+2, false));
          }

          amin = min(amin, atime);
        }

        if (ok && memo2[atop.kx][atop.ky][tway] > atop.turn + amin) {
          memo2[atop.kx][atop.ky][tway] = atop.turn + amin;
          que.push({atop.kx, atop.ky, tway, atop.turn + amin});
        }
      }

      int nkx = atop.kx + dx[atop.opway];
      int nky = atop.ky + dy[atop.opway];
      int nway = (atop.opway + 2) % 4;

      if (memo2[nkx][nky][nway] > atop.turn + 1) {
        memo2[nkx][nky][nway] = atop.turn + 1;
        que.push({nkx, nky, nway, atop.turn + 1});
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dx2[4] = {-1, 0, 2, 1};
const int dy2[4] = {0, 2, 1, -1};

struct aa {
  int x;
  int y;
  int turn;
};

int getdis(const int* field, const int* lookup, const int fx, const int fy,
           const int gx, const int gy, const int W) {
  return lookup[fx * W + fy + gx * W + gy];
}

struct bb {
  int kx;
  int ky;
  int opway;
  int turn;
};

class Compare {
public:
  bool operator()(const bb &l, const bb &r) { return l.turn > r.turn; }
};

int main() {
  while (1) {
    int H, W;
    cin >> H >> W;
    if (!H)
      break;
    
    int field_size = (H + 2) * (W + 2);
    int* field = new int[field_size];
    int* lookup = new int[field_size * field_size];

    // Initialize field
    for (int i = 0; i < field_size; i++) {
      field[i] = true;
    }

    // Read the grid
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
    
    // Precompute distances
    for (int i = 0; i < field_size; i++) {
      for (int j = 0; j < field_size; j++) {
        lookup[i * field_size + j] = 999999;
      }
    }
    
    for (int fx = 1; fx <= H; fx++) {
      for (int fy = 1; fy <= W; fy++) {
        if (field[fx * (W + 2) + fy]) continue;
        for (int gx = 1; gx <= H; gx++) {
          for (int gy = 1; gy <= W; gy++) {
            if (field[gx * (W + 2) + gy]) continue;
            queue<aa> que;
            vector<vector<int>> memo(H + 2, vector<int>(W + 2, 999999));
            que.push(aa{fx, fy, 0});
            while (!que.empty()) {
              aa atop(que.front());
              que.pop();
              if (atop.x == gx && atop.y == gy) {
                lookup[fx * field_size + fy + gx * field_size + gy] = atop.turn;
                break;
              }
              for (int i = 0; i < 4; ++i) {
                const int nextx = atop.x + dx[i];
                const int nexty = atop.y + dy[i];
                if (!field[nextx * (W + 2) + nexty]) {
                  if (atop.turn + 1 < memo[nextx][nexty]) {
                    memo[nextx][nexty] = atop.turn + 1;
                    que.push(aa{nextx, nexty, atop.turn + 1});
                  }
                }
              }
            }
          }
        }
      }
    }
    
    // Initialize memo2
    int*** memo2 = new int**[W + 2];
    for (int i = 0; i < W + 2; i++) {
      memo2[i] = new int*[H + 2];
      for (int j = 0; j < H + 2; j++) {
        memo2[i][j] = new int[4];
      }
    }
    for (int i = 0; i < W + 2; i++) {
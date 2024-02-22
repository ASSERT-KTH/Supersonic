#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <vector>

const int kMaxSize = 32;
const int kMaxField = kMaxSize * kMaxSize;
const int kInf = 1 << 16;
const char kWall = '#';
const char kFriend = 'o';
const char kEnemy = 'x';
const char kStart = 'S';
const char kGoal = 'G';
const char kBlank = '.';

char field[kMaxField];
int way[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int d[kMaxField];
int cost[kMaxField][kMaxField];

int R, C;

inline int xy2pos(const int x, const int y) { return x + y * kMaxSize; }

void initCost() {
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      if (field[pos] == kWall)
        continue;
      for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= 3; j++) {
          int nx = x + j * way[i][0];
          int ny = y + j * way[i][1];
          if (nx < 1 || nx > C || ny < 1 || ny > R || field[xy2pos(nx, ny)] == kWall)
            break;
          int newpos = xy2pos(nx, ny);
          int newcost;
          if (field[newpos] == kFriend)
            newcost = j + 1;
          else if (field[newpos] == kEnemy)
            newcost = j + 3;
          else
            newcost = j + 2;
          cost[pos][newpos] = newcost;
        }
      }
    }
  }
}

void dijkstra(int spos) {
  std::vector<int> visited(kMaxField, 0);
  std::fill(d, d + kMaxField, kInf);
  d[spos] = 0;
  for (int i = 0; i < R * C; i++) {
    int min_cost = kInf;
    int min_pos = -1;
    for (int j = 0; j < R * C; j++) {
      if (!visited[j] && d[j] < min_cost) {
        min_cost = d[j];
        min_pos = j;
      }
    }
    if (min_pos == -1)
      break;
    visited[min_pos] = 1;
    for (int j = 0; j < R * C; j++) {
      if (!visited[j] && cost[min_pos][j] != 0 && d[j] > d[min_pos] + cost[min_pos][j]) {
        d[j] = d[min_pos] + cost[min_pos][j];
      }
    }
  }
}

int main() {
  int start, goal;
  std::scanf("%d %d", &R, &C);
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      std::scanf(" %c", &field[pos]);
      if (field[pos] == kStart)
        start = pos;
      else if (field[pos] == kGoal)
        goal = pos;
    }
  }
  initCost();
  dijkstra(start);
  std::printf("%d\n", d[goal]);
  return 0;
}
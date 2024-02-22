#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <vector>

struct Edge {
  int to, cost;
};

const int kMaxSize = 32;
const int kMaxField = kMaxSize * kMaxSize;
const int kCostFriendlyInk = 1;
const int kCostShot = 2;
const int kCostBlank = 2;
const int kShotRange = 3;
const char kWall = '#';
const char kFriend = 'o';
const char kEnemy = 'x';
const char kStart = 'S';
const char kGoal = 'G';
const char kBlank = '.';

char field[kMaxField];
int way[4] = {-1, 1, -kMaxSize, kMaxSize};
const int kInf = 1 << 16;
int d[kMaxField];
Edge cost[kMaxField];

inline int xy2pos(const int x, const int y) {
  return x + y * kMaxSize;
}

void initCost() {
  for (int pos = 0; pos < kMaxField; pos++) {
    if (field[pos] == kWall)
      continue;

    for (int i = 0; i < 4; i++) {
      for (int j = 1; j <= kShotRange; j++) {
        int newpos = pos + j * way[i];
        if (field[newpos] == kWall)
          break;

        int newcost;
        if (j == 1) {
          if (field[newpos] == kFriend)
            newcost = kCostFriendlyInk;
          else if (field[newpos] == kEnemy)
            newcost = kCostShot + kCostFriendlyInk;
          else
            newcost = kCostBlank;
        } else {
          if (field[newpos] == kFriend)
            newcost = std::min(kCostShot + kCostFriendlyInk * j, cost[pos].cost + kCostFriendlyInk);
          else if (field[newpos] == kEnemy)
            newcost = kCostShot + kCostFriendlyInk * j;
          else
            newcost = std::min(kCostShot + kCostFriendlyInk * j, cost[pos].cost + kCostBlank);
        }

        cost[pos].push_back({newpos, newcost});
      }
    }
  }
}

void dijkstra(int spos) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> q;
  std::fill(d, d + kMaxField, kInf);
  d[spos] = 0;
  q.push(spos);

  while (!q.empty()) {
    int p = q.top();
    q.pop();

    if (d[p] == kInf)
      break;

    for (const Edge& e : cost[p]) {
      if (d[e.to] > d[p] + e.cost) {
        d[e.to] = d[p] + e.cost;
        q.push(e.to);
      }
    }
  }
}

int main() {
  int start, goal;
  std::fill(field, field + kMaxField, '#');
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
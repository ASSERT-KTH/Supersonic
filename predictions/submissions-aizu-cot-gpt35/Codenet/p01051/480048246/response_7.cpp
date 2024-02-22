#include <cstdio>
#include <queue>
#include <vector>

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

struct Edge {
  int to, cost;
};

const int kInf = 1 << 16;
int d[kMaxField];
std::vector<Edge> cost[kMaxField];
int R, C;
int way[4] = {-1, 1, -kMaxSize, kMaxSize};

inline int xy2pos(const int x, const int y) { return x + y * kMaxSize; }

void initCost() {
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      if (field[y][x] == kWall)
        continue;
      for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= kShotRange; j++) {
          int newpos = pos + j * way[i];
          if (field[newpos / kMaxSize][newpos % kMaxSize] == kWall)
            break;
          if (j == 1) {
            if (field[newpos / kMaxSize][newpos % kMaxSize] == kFriend)
              cost[pos].push_back({newpos, kCostFriendlyInk});
            else if (field[newpos / kMaxSize][newpos % kMaxSize] == kEnemy)
              cost[pos].push_back({newpos, kCostShot + kCostFriendlyInk});
            else
              cost[pos].push_back({newpos, kCostBlank});
          } else {
            int newcost;
            if (field[newpos / kMaxSize][newpos % kMaxSize] == kFriend)
              newcost = std::min(kCostShot + kCostFriendlyInk * j,
                                 cost[pos].back().cost + kCostFriendlyInk);
            else if (field[newpos / kMaxSize][newpos % kMaxSize] == kEnemy)
              newcost = kCostShot + kCostFriendlyInk * j;
            else
              newcost = std::min(kCostShot + kCostFriendlyInk * j,
                                 cost[pos].back().cost + kCostBlank);
            cost[pos].push_back({newpos, newcost});
          }
        }
      }
    }
  }
}

void dijkstra(int spos) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;
  std::fill(d, d + kMaxField, kInf);
  d[spos] = 0;
  q.push({0, spos});
  while (!q.empty()) {
    auto p = q.top();
    q.pop();
    if (d[p.second] < p.first)
      continue;
    for (auto e : cost[p.second]) {
      if (d[e.to] > d[p.second] + e.cost) {
        d[e.to] = d[p.second] + e.cost;
        q.push({d[e.to], e.to});
      }
    }
  }
}

int main() {
  int start, goal;
  char field[kMaxSize][kMaxSize];
  std::fill(&field[0][0], &field[0][0] + sizeof(field), '#');
  std::scanf("%d %d", &R, &C);
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      std::scanf(" %c", &field[y][x]);
      if (field[y][x] == kStart)
        start = xy2pos(x, y);
      else if (field[y][x] == kGoal)
        goal = xy2pos(x, y);
    }
  }
  initCost();
  dijkstra(start);
  printf("%d\n", d[goal]);
  return 0;
}
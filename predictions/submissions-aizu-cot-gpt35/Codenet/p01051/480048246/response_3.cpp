#include <cstdio>

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
int cost[kMaxField][kShotRange + 1];
int R, C;

inline int xy2pos(const int x, const int y) {
  return x + y * kMaxSize;
}

void initCost() {
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      if (field[pos] == kWall)
        continue;
      for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= kShotRange; j++) {
          int newpos = pos + j * way[i];
          if (field[newpos] == kWall)
            break;
          if (j == 1) {
            if (field[newpos] == kFriend)
              cost[pos][j] = kCostFriendlyInk;
            else if (field[newpos] == kEnemy)
              cost[pos][j] = kCostShot + kCostFriendlyInk;
            else
              cost[pos][j] = kCostBlank;
          } else {
            int newcost;
            if (field[newpos] == kFriend)
              newcost = (kCostShot + kCostFriendlyInk * j) < (cost[pos][j - 1] + kCostFriendlyInk) ? (kCostShot + kCostFriendlyInk * j) : (cost[pos][j - 1] + kCostFriendlyInk);
            else if (field[newpos] == kEnemy)
              newcost = kCostShot + kCostFriendlyInk * j;
            else
              newcost = (kCostShot + kCostFriendlyInk * j) < (cost[pos][j - 1] + kCostBlank) ? (kCostShot + kCostFriendlyInk * j) : (cost[pos][j - 1] + kCostBlank);
            cost[pos][j] = newcost;
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
  q.push(std::make_pair(0, spos));
  while (!q.empty()) {
    std::pair<int, int> p = q.top();
    q.pop();
    if (d[p.second] < p.first)
      continue;
    for (int i = 0; i < kShotRange; i++) {
      int newpos = p.second + way[i];
      if (field[newpos] == kWall)
        continue;
      int newcost = d[p.second] + cost[p.second][1];
      if (d[newpos] > newcost) {
        d[newpos] = newcost;
        q.push(std::make_pair(d[newpos], newpos));
      }
    }
  }
}

int main() {
  int start, goal;
  std::fill(field, field + kMaxField, '#');
  scanf("%d %d", &R, &C);
  for (int y = 1; y <= R; y++)
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      scanf(" %c", &field[pos]);
      if (field[pos] == kStart)
        start = pos;
      else if (field[pos] == kGoal)
        goal = pos;
    }
  initCost();
  dijkstra(start);
  printf("%d\n", d[goal]);
  return 0;
}
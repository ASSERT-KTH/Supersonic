#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
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
char field[kMaxField];
int way[4] = {-1, 1, -kMaxSize, kMaxSize};
const int kInf = 1 << 16;
int d[kMaxField];
std::vector<std::pair<int, int>> cost[kMaxField];
int R, C;
inline int xy2pos(const int x, const int y) { return x + y * kMaxSize; }
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
          int newcost;
          if (field[newpos] == kFriend)
            newcost = kCostShot + kCostFriendlyInk * j;
          else if (field[newpos] == kEnemy)
            newcost = kCostShot + kCostFriendlyInk * j;
          else
            newcost = kCostShot + kCostFriendlyInk * j;
          cost[pos].emplace_back(newpos, newcost);
        }
      }
    }
  }
}
void dijkstra(int spos) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> q;
  std::fill(d, d + kMaxField, kInf);
  d[spos] = 0;
  q.emplace(0, spos);
  while (!q.empty()) {
    auto [dist, pos] = q.top();
    q.pop();
    if (d[pos] < dist)
      continue;
    for (auto& [to, cost] : cost[pos]) {
      if (d[to] > d[pos] + cost) {
        d[to] = d[pos] + cost;
        q.emplace(d[to], to);
      }
    }
  }
}
int main() {
  int start, goal;
  std::fill(field, field + kMaxField, '#');
  std::scanf("%d %d", &R, &C);
  for (int y = 1; y <= R; y++)
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      std::scanf(" %c", &field[pos]);
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
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
typedef struct {
  int to, cost;
} Edge;
typedef std::pair<int, int> P;
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
std::vector<Edge> cost[kMaxField];
int R, C;
inline int xy2pos(const int x, const int y) { return x + y * kMaxSize; }
void initCost() {
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      if (field[pos] == kWall)
        continue;
      int newcost;
      for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= kShotRange; j++) {
          int newpos = pos + j * way[i];
          if (field[newpos] == kWall)
            break;
          if (field[newpos] == kFriend)
            newcost = (j == 1) ? kCostFriendlyInk : std::min(kCostShot + kCostFriendlyInk * j, cost[pos].back().cost + kCostFriendlyInk);
          else if (field[newpos] == kEnemy)
            newcost = kCostShot + kCostFriendlyInk * j;
          else
            newcost = (j == 1) ? kCostBlank : std::min(kCostShot + kCostFriendlyInk * j, cost[pos].back().cost + kCostBlank);
          cost[pos].push_back({newpos, newcost});
        }
      }
    }
  }
}
void dijkstra(int spos) {
  std::priority_queue<P, std::vector<P>, std::greater<P>> q;
  std::fill(d, d + kMaxField, kInf);
  d[spos] = 0;
  q.push(P(0, spos));
  while (!q.empty()) {
    P p = q.top();
    q.pop();
    if (d[p.second] < p.first)
      continue;
    for (Edge& e : cost[p.second]) {
      int newCost = d[p.second] + e.cost;
      if (d[e.to] > newCost) {
        d[e.to] = newCost;
        q.push(P(newCost, e.to));
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
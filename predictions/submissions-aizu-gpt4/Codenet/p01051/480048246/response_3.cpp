#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <vector>
struct Edge {
  int to, cost;
};
using P = std::pair<int, int>;
constexpr int kMaxSize = 32;
constexpr int kMaxField = kMaxSize * kMaxSize;
constexpr int kCostFriendlyInk = 1;
constexpr int kCostShot = 2;
constexpr int kCostBlank = 2;
constexpr int kShotRange = 3;
constexpr char kWall = '#';
constexpr char kFriend = 'o';
constexpr char kEnemy = 'x';
constexpr char kStart = 'S';
constexpr char kGoal = 'G';
constexpr char kBlank = '.';
char field[kMaxField];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
constexpr int kInf = 1 << 16;
int d[kMaxField];
std::vector<Edge> cost[kMaxField];
int R, C;
inline int xy2pos(const int x, const int y) { return x + y * kMaxSize; }
void initCost() {
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      if (field[pos] == kWall) continue;
      for (int i = 0; i < 4; i++) {
        for (int j = 1; j <= kShotRange; j++) {
          int nx = x + dx[i] * j, ny = y + dy[i] * j;
          if (nx <= 0 || ny <= 0 || nx > C || ny > R) break;
          int newpos = xy2pos(nx, ny);
          if (field[newpos] == kWall) break;
          int newcost = (field[newpos] == kFriend ? kCostFriendlyInk : (field[newpos] == kEnemy ? kCostFriendlyInk + kCostShot : kCostBlank)) + (j > 1 ? cost[pos].back().cost : 0);
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
    if (d[p.second] < p.first) continue;
    for (const auto& e : cost[p.second]) {
      if (d[e.to] > d[p.second] + e.cost) {
        d[e.to] = d[p.second] + e.cost;
        q.push(P(d[e.to], e.to));
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
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <utility>
#include <queue>
#include <vector>

typedef std::pair<int, int> P;
const int kMaxSize = 32;
const int kMaxField = kMaxSize * kMaxSize;
const int kInf = 1 << 16;

char field[kMaxField];
int d[kMaxField];
std::vector<P> cost[kMaxField];

int R, C;
inline int xy2pos(const int x, const int y) { return x + y * kMaxSize; }

void initCost() {
  int way[4] = {-1, 1, -kMaxSize, kMaxSize};
  const int kShotRange = 3;
  for (int y = 1; y <= R; y++) {
    for (int x = 1; x <= C; x++) {
      int pos = xy2pos(x, y);
      if (field[pos] == '#')
        continue;
      for (int i = 0; i < 4; i++) {
        int newcost = 0;
        for (int j = 1; j <= kShotRange; j++) {
          int newpos = pos + j * way[i];
          if (field[newpos] == '#')
            break;
          newcost += (field[newpos] == 'x') + (field[newpos] == 'o') * (j + 1);
          cost[pos].emplace_back(newpos, newcost);
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
    for (const auto& e: cost[p.second]) {
      if (d[e.first] > d[p.second] + e.second) {
        d[e.first] = d[p.second] + e.second;
        q.push(P(d[e.first], e.first));
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
      if (field[pos] == 'S')
        start = pos;
      else if (field[pos] == 'G')
        goal = pos;
    }
  initCost();
  dijkstra(start);
  printf("%d\n", d[goal]);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

constexpr int MAX_H = 60;
constexpr int MAX_W = 60;
constexpr int INF = 1e9;
constexpr array<int, 4> dx = {-1, 0, 1, 0};
constexpr array<int, 4> dy = {0, 1, 0, -1};

struct Node {
  int x, y, turn;
};

struct State {
  int x, y, dir, cost;
  bool operator>(const State &s) const {
    return cost > s.cost;
  }
};

int dist[MAX_H][MAX_W], cost[MAX_H][MAX_W][4];
vector<vector<int>> field;

int bfs(int sx, int sy, int gx, int gy) {
  fill(&dist[0][0], &dist[MAX_H-1][MAX_W], INF);
  queue<Node> q;
  dist[sy][sx] = 0;
  q.push({sx, sy, 0});

  while (!q.empty()) {
    Node cur = q.front(); q.pop();
    if (cur.x == gx && cur.y == gy) return cur.turn;

    for (int i = 0; i < 4; ++i) {
      int nx = cur.x + dx[i], ny = cur.y + dy[i];
      if (field[ny][nx] || dist[ny][nx] <= cur.turn + 1) continue;
      dist[ny][nx] = cur.turn + 1;
      q.push({nx, ny, cur.turn + 1});
    }
  }

  return INF;
}

int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);

  while (true) {
    int H, W;
    cin >> H >> W;
    if (H == 0 && W == 0) break;

    fill(&cost[0][0][0], &cost[MAX_H-1][MAX_W][4], INF);
    field.assign(H + 2, vector<int>(W + 2, 1));

    int sx = INF, sy = INF, gx[2], gy[2];
    for (int y = 1; y <= H; ++y) {
      string s;
      cin >> s;
      for (int x = 1; x <= W; ++x) {
        if (s[x-1] == 'X') {
          sx = min(sx, x);
          sy = min(sy, y);
          field[y][x] = 0;
        } else if (s[x-1] == '.') {
          gx[0] = x, gy[0] = y;
          swap(gx[0], gx[1]), swap(gy[0], gy[1]);
          field[y][x] = 0;
        } else if (s[x-1] == 'o') {
          field[y][x] = 0;
        }
      }
    }

    if (sx == 1 && sy == 1) { cout << 0 << "\n"; continue; }

    priority_queue<State, vector<State>, greater<State>> pq;
    for (int dir = 0; dir < 4; ++dir) {
      int nx = sx + dx[dir], ny = sy + dy[dir];
      if (field[ny][nx]) continue;
      int min_cost = INF;
      for (int i = 0; i < 2; ++i) {
        field[sy][sx] = 1, field[ny][nx] = 1;
        int cost_1 = bfs(gx[i], gy[i], sx, sy);
        int cost_2 = bfs(gx[1-i], gy[1-i], nx, ny);
        field[sy][sx] = 0, field[ny][nx] = 0;
        min_cost = min(min_cost, cost_1 + cost_2);
      }
      if (min_cost < INF) {
        cost[sx][sy][dir] = min_cost;
        pq.push({sx, sy, dir, min_cost});
      }
    }

    int ans = -1;
    while (!pq.empty()) {
      State cur = pq.top(); pq.pop();
      if (cur.cost > cost[cur.x][cur.y][cur.dir]) continue;
      if (cur.x == 1 && cur.y == 1) { ans = cur.cost; break; }

      for (int dir = 0; dir < 4; ++dir) {
        if (dir == cur.dir) continue;
        int nx = cur.x + dx[dir], ny = cur.y + dy[dir];
        if (field[ny][nx]) continue;
        int min_cost = INF;
        for (int i = 0; i < 2; ++i) {
          field[cur.y][cur.x] = 1, field[ny][nx] = 1;
          int cost_1 = bfs(gx[i], gy[i], cur.x, cur.y);
          int cost_2 = bfs(gx[1-i], gy[1-i], nx, ny);
          field[cur.y][cur.x] = 0, field[ny][nx] = 0;
          min_cost = min(min_cost, cost_1 + cost_2);
        }
        if (min_cost < INF && cur.cost + min_cost < cost[cur.x][cur.y][dir]) {
          cost[cur.x][cur.y][dir] = cur.cost + min_cost;
          pq.push({cur.x, cur.y, dir, cur.cost + min_cost});
        }
      }

      int nx = cur.x + dx[cur.dir], ny = cur.y + dy[cur.dir];
      int ndir = (cur.dir + 2) % 4;
      if (cur.cost + 1 < cost[nx][ny][ndir]) {
        cost[nx][ny][ndir] = cur.cost + 1;
        pq.push({nx, ny, ndir, cur.cost + 1});
      }
    }

    cout << ans << "\n";
  }

  return 0;
}
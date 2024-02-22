#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
#include <stack>

using namespace std;

const int N = 49;
int w, h;
vector<vector<int>> field, vertex, edge;
bitset<N> visited;
set<unsigned long long> memo;

void make_graph() {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;

  // Clear the existing graph if any
  for (auto &row : vertex)
    fill(row.begin(), row.end(), NIL);
  for (auto &e : edge)
    e.clear();

  int size = 0;
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        vertex[y][x] = size++;

  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x) {
      if (vertex[y][x] == NIL)
        continue;
      for (const auto &d : NEXT) {
        int ny = y + d[Y];
        int nx = x + d[X];
        if (ny < 0 || h <= ny || nx < 0 || w <= nx)
          continue;
        if (vertex[ny][nx] == NIL)
          continue;
        edge[vertex[y][x]].push_back(vertex[ny][nx]);
      }
    }
}

void reachability(int from) {
  stack<int> stk;
  stk.push(from);

  while (!stk.empty()) {
    int curr = stk.top();
    stk.pop();

    if (visited[curr]) continue;
    visited.set(curr);

    for (const auto &to : edge[curr])
      if (!visited[to])
        stk.push(to);
  }
}

bool cut_vertex(int from) {
  auto dup = visited;
  dup.set(from);

  for (const auto &to : edge[from]) {
    if (dup[to])
      continue;
    reachability(to);
  }
  return dup.count() != vertex[h-1][w-1] + 1;
}

bool dfs(int start, int from) {
  // Rest of the code remains the same
}

bool solve() {
  visited = bitset<N>(0);
  make_graph();
  memo.clear();

  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        return dfs(vertex[y][x], vertex[y][x]);
  return false;
}

// Rest of the code remains the same
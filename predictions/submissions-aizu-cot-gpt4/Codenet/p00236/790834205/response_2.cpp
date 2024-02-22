#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
#include <stack>
using namespace std;
const int N = 49;
int w, h;
int field[N][N];
int size;
int vertex[N][N];
vector<int> edge[N * N];
bitset<N> visited;
set<unsigned long long> memo;
void make_graph() {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  size = 0;
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      vertex[y][x] = field[y][x] ? NIL : size++;
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x) {
      if (vertex[y][x] == NIL)
        continue;
      for (const auto &d : NEXT) {
        int ny = y + d[Y];
        int nx = x + d[X];
        if (ny < 0 || h <= ny || nx < 0 || w <= nx)
          continue;
        if (vertex[ny][nx] != NIL)
          edge[vertex[y][x]].push_back(vertex[ny][nx]);
      }
    }
};
void reachability(const int &from, bitset<N> &visited) {
  stack<int> stack;
  stack.push(from);
  while (!stack.empty()) {
    int v = stack.top(); stack.pop();
    visited.set(v);
    for (const auto &to : edge[v])
      if (!visited[to])
        stack.push(to);
  }
}
bool cut_vertex(const int &from) {
  auto dup = visited;
  dup.set(from);
  for (const auto &to : edge[from]) {
    if (!dup[to]) {
      reachability(to, dup);
      if (dup.count() != size)
        return true;
    }
  }
  return dup.count() != size;
}
bool dfs(const int &start, int from) {
  unsigned long long m = visited.to_ullong() * N + from;
  if (memo.count(m))
    return false;
  memo.insert(m);
  if (cut_vertex(from))
    return false;
  for (int u = 0; u < size; ++u) {
    if (u == from || visited[u])
      continue;
    int degree = 0;
    for (const auto &v : edge[u])
      if (v == start || !visited[v])
        ++degree;
    if (degree < 2)
      return false;
  }
  visited.set(from);
  for (const auto &to : edge[from]) {
    if (to == start && visited.count() == size)
      return true;
    if (!visited[to] && dfs(start, to))
      return true;
  }
  visited.reset(from);
  return false;
}
bool solve() {
  visited = bitset<N>(0);
  make_graph();
  memo.clear();
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x] && dfs(vertex[y][x], vertex[y][x]))
        return true;
  return false;
}
int main() {
  while (cin >> w >> h, w | h) {
    for (int y = 0; y < h; ++y)
      for (int x = 0; x < w; ++x)
        cin >> field[y][x];
    cout << (solve() ? "Yes" : "No") << endl;
  }
}
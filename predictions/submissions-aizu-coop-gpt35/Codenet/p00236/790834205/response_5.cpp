#include <algorithm>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
int field[N][N];
int size;
int vertex[N][N];
vector<int> edge[N * N];
bool visited[N];
set<unsigned long long> memo;
void make_graph() {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  size = 0;
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
};
void reachability(const int &from) {
  visited[from] = true;
  vector<int> stack;
  stack.push_back(from);
  while (!stack.empty()) {
    int current = stack.back();
    stack.pop_back();
    for (const auto &to : edge[current]) {
      if (!visited[to]) {
        visited[to] = true;
        stack.push_back(to);
      }
    }
  }
}
bool cut_vertex(const int &from) {
  fill(visited, visited + N, false);
  visited[from] = true;
  for (const auto &to : edge[from]) {
    if (!visited[to]) {
      reachability(to);
      return false;
    }
  }
  return true;
}
bool dfs(const int &start, int from) {
  unsigned long long m = from;
  for (int i = 0; i < size; ++i) {
    m = m * N + visited[i];
  }
  if (memo.count(m))
    return false;
  memo.insert(m);
  if (cut_vertex(from))
    return false;
  for (int u = 0; u < size; ++u) {
    if (u == from)
      continue;
    if (visited[u])
      continue;
    int degree = 0;
    for (const auto &v : edge[u])
      if (v == start || !visited[v])
        ++degree;
    if (degree < 2)
      return false;
  }
  visited[from] = true;
  for (const auto &to : edge[from]) {
    if (to == start && count(visited, visited + N, true) == size)
      return true;
    if (visited[to])
      continue;
    if (dfs(start, to))
      return true;
  }
  visited[from] = false;
  return false;
}
bool solve() {
  make_graph();
  memo.clear();
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        return dfs(vertex[y][x], vertex[y][x]);
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
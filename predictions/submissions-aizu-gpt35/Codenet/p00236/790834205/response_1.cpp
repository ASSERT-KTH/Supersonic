#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
vector<vector<int>> field;
int size;
vector<vector<int>> vertex;
vector<vector<int>> edge;
int visited[N];
set<unsigned long long> memo;
void make_graph() {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  size = 0;
  vertex = vector<vector<int>>(h, vector<int>(w, NIL));
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        vertex[y][x] = size++;
  edge = vector<vector<int>>(h * w, vector<int>());
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
  visited[from] = 1;
  for (const auto &to : edge[from])
    if (!visited[to])
      reachability(to);
}
bool cut_vertex(const int &from) {
  auto dup = visited;
  dup[from] = 1;
  for (const auto &to : edge[from]) {
    if (dup[to])
      continue;
    reachability(to);
    if(dup.count() != size)
      return true;
  }
  return dup.count() != size;
}
bool dfs(const int &start, int from) {
  unsigned long long m = visited[0];
  for(int i=1; i<N; ++i)
    m = m * N + visited[i];
  m = m * N + from;
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
  visited[from] = 1;
  for (const auto &to : edge[from]) {
    if (to == start && count(visited, visited+size, 1) == size)
      return true;
    if (visited[to])
      continue;
    if (dfs(start, to))
      return true;
  }
  visited[from] = 0;
  return false;
}
bool solve() {
  fill(visited, visited+N, 0);
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
    field = vector<vector<int>>(h, vector<int>(w));
    for (auto &line : field)
      for (auto &v : line)
        cin >> v;
    cout << (solve() ? "Yes" : "No") << endl;
  }
}
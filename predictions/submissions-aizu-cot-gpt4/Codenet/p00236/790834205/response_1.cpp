#include <algorithm>
#include <bitset>
#include <iostream>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
vector<vector<int>> field;
int size;
vector<vector<int>> vertex;
vector<vector<int>> edge;
bitset<N> visited;
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
      if (vertex[y][x] != NIL)
        for (const auto &d : NEXT) {
          int ny = y + d[Y], nx = x + d[X];
          if (0 <= ny && ny < h && 0 <= nx && nx < w && vertex[ny][nx] != NIL)
            edge[vertex[y][x]].push_back(vertex[ny][nx]);
        }
    }
};
void reachability(int from, bitset<N> &visited) {
  visited.set(from);
  for (const auto &to : edge[from])
    if (!visited[to])
      reachability(to, visited);
}
bool cut_vertex(int from) {
  visited.set(from);
  for (const auto &to : edge[from]) {
    if (!visited[to]) {
      auto dup = visited;
      reachability(to, dup);
      if (dup.count() != size)
        return true;
    }
  }
  return visited.count() != size;
}
bool dfs(int start, int from) {
  unsigned long long m = visited.to_ullong() * N + from;
  if (!memo.insert(m).second || cut_vertex(from))
    return false;
  visited.set(from);
  int count = visited.count();
  for (int u = 0; u < size; ++u) {
    int degree = 0;
    if (u != from && !visited[u]) {
      for (const auto &v : edge[u])
        if (v == start || !visited[v])
          ++degree;
      if (degree < 2)
        return false;
    }
  }
  for (const auto &to : edge[from]) {
    if (to == start && count == size)
      return true;
    else if (!visited[to] && dfs(start, to))
      return true;
  }
  visited.reset(from);
  return false;
}
bool solve() {
  visited.reset();
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
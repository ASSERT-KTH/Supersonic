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
bitset<N * N> memo;
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
  edge = vector<vector<int>>(size);
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x) {
      if (vertex[y][x] == NIL)
        continue;
      for (const auto &d : NEXT) {
        int ny = y + d[Y];
        int nx = x + d[X];
        if (ny >= 0 && ny < h && nx >= 0 && nx < w && vertex[ny][nx] != NIL)
          edge[vertex[y][x]].push_back(vertex[ny][nx]);
      }
    }
};
void reachability(const int &from, bitset<N> &visited) {
  visited.set(from);
  for (const auto &to : edge[from])
    if (!visited[to])
      reachability(to, visited);
}
bool cut_vertex(const int &from) {
  auto dup = visited;
  dup.set(from);
  for (const auto &to : edge[from]) {
    if (dup[to])
      continue;
    reachability(to, dup);
    if (dup.count() != size)
      return true;
  }
  return false;
}
bool dfs(const int &start, int from) {
  unsigned long long m = visited.to_ullong() * N + from;
  if (memo[m])
    return false;
  memo[m] = 1;
  if (cut_vertex(from))
    return false;
  visited.set(from);
  for (const auto &to : edge[from]) {
    if (visited[to])
      continue;
    if (to == start && visited.count() == size)
      return true;
    if (dfs(start, to))
      return true;
  }
  visited.reset(from);
  return false;
}
bool solve() {
  visited.reset();
  make_graph();
  memo.reset();
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
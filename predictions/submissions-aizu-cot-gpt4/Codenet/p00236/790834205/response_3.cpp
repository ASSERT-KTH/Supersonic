#include <vector>
#include <iostream>
using namespace std;
const int N = 49;
int w, h;
vector<vector<int>> field;
int size;
vector<vector<int>> vertex;
vector<vector<int>> edge;
vector<bool> visited, reachable;
vector<int> degree;
vector<bool> memo;
void make_graph() {
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  size = 0;
  vertex = vector<vector<int>>(h, vector<int>(w, NIL));
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        vertex[y][x] = size++;
  edge = vector<vector<int>>(size);
  degree = vector<int>(size);
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x) {
      if (vertex[y][x] == NIL)
        continue;
      for (const auto &d : NEXT) {
        int ny = y + d[0];
        int nx = x + d[1];
        if (ny < 0 || h <= ny || nx < 0 || w <= nx)
          continue;
        if (vertex[ny][nx] == NIL)
          continue;
        edge[vertex[y][x]].push_back(vertex[ny][nx]);
        ++degree[vertex[y][x]];
      }
    }
}
void reachability(int from) {
  visited[from] = true;
  for (const auto &to : edge[from])
    if (!visited[to])
      reachability(to);
}
bool dfs(const int &start, int from) {
  unsigned long long m = from;
  if (memo[m])
    return false;
  memo[m] = true;
  if (!reachable[from])
    return false;
  for (int u = 0; u < size; ++u) {
    if (u == from)
      continue;
    if (visited[u])
      continue;
    if (degree[u] < 2)
      return false;
  }
  visited[from] = true;
  for (const auto &to : edge[from]) {
    if (to == start && visited.size() == size)
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
  visited = vector<bool>(size, false);
  reachable = vector<bool>(size, false);
  make_graph();
  memo = vector<bool>(size, false);
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x]) {
        reachability(vertex[y][x]);
        return dfs(vertex[y][x], vertex[y][x]);
      }
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
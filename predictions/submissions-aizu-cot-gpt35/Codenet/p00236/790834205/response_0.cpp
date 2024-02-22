#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
vector<vector<bool>> field;
int size;
vector<vector<int>> vertex;
vector<vector<int>> edge;
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

bool dfs(const int &start, int from, bitset<N>& visited, const vector<int>& degree) {
  unsigned long long m = visited.to_ullong() * N + from;
  if (memo.count(m))
    return false;
  memo.insert(m);
  
  visited.set(from);
  for (const auto &to : edge[from]) {
    if (to == start && visited.count() == size)
      return true;
    if (visited[to])
      continue;
    if (degree[to] >= 2 && dfs(start, to, visited, degree))
      return true;
  }
  visited.reset(from);
  return false;
}

bool solve() {
  bitset<N> visited;
  make_graph();
  memo.clear();
  vector<int> degree(size, 0);
  for (int u = 0; u < size; ++u) {
    for (const auto &v : edge[u])
      if (v == u || !visited[v])
        ++degree[u];
  }
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        return dfs(vertex[y][x], vertex[y][x], visited, degree);
  return false;
}

int main() {
  while (cin >> w >> h, w | h) {
    field = vector<vector<bool>>(h, vector<bool>(w));
    for (auto &line : field)
      for (auto &v : line)
        cin >> v;
    cout << (solve() ? "Yes" : "No") << endl;
  }
}
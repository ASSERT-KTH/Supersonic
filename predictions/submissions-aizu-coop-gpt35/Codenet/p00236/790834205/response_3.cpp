#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
vector<int> field;
int size;
vector<int> vertex;
vector<vector<int>> edge;
vector<bitset<N>> reachability;

void make_graph() {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  size = 0;
  vertex = vector<int>(h * w, NIL);
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y * w + x])
        vertex[y * w + x] = size++;
  edge = vector<vector<int>>(h * w, vector<int>());
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x) {
      if (vertex[y * w + x] == NIL)
        continue;
      for (const auto &d : NEXT) {
        int ny = y + d[Y];
        int nx = x + d[X];
        if (ny < 0 || h <= ny || nx < 0 || w <= nx)
          continue;
        if (vertex[ny * w + nx] == NIL)
          continue;
        edge[vertex[y * w + x]].push_back(vertex[ny * w + nx]);
      }
    }
};

void computeReachability(const int &from, bitset<N> &visited) {
  visited.set(from);
  for (const auto &to : edge[from])
    if (!visited[to])
      computeReachability(to, visited);
}

bool cut_vertex(const int &from) {
  auto dup = reachability[from];
  dup.set(from);
  for (const auto &to : edge[from]) {
    if (dup[to])
      continue;
    return dup.count() != size;
  }
  return dup.count() != size;
}

bool dfs(const int &start, int from) {
  if (cut_vertex(from))
    return false;
  for (int u = 0; u < size; ++u) {
    if (u == from)
      continue;
    if (reachability[u][from])
      continue;
    int degree = 0;
    for (const auto &v : edge[u])
      if (v == start || !reachability[v][u])
        ++degree;
    if (degree < 2)
      return false;
  }
  for (const auto &to : edge[from]) {
    if (to == start && reachability[from].count() == size)
      return true;
    if (!reachability[to][from])
      continue;
    if (dfs(start, to))
      return true;
  }
  return false;
}

bool solve() {
  make_graph();
  reachability = vector<bitset<N>>(size, bitset<N>(0));
  for (int i = 0; i < size; ++i) {
    computeReachability(i, reachability[i]);
  }
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y * w + x])
        return dfs(vertex[y * w + x], vertex[y * w + x]);
  return false;
}

int main() {
  while (cin >> w >> h, w | h) {
    field = vector<int>(h * w);
    for (auto &v : field)
      cin >> v;
    cout << (solve() ? "Yes" : "No") << endl;
  }
}
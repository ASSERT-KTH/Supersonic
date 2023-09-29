#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
vector<int> vertex;
vector<vector<int>> edge;
bitset<N> visited;
set<unsigned long long> memo;
void make_graph(vector<vector<int>>& field) {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  int size = 0;
  vertex.assign(h * w, NIL);
  for (int i = 0; i < h * w; ++i) {
    if (!field[i / w][i % w])
      vertex[i] = size++;
  }
  edge.resize(size);
  for (int y = 0; y < h; ++y) {
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
  }
};
void reachability(const int &from, bitset<N> &visited) {
  visited.set(from);
  for (const auto &to : edge[from])
    if (!visited[to])
      reachability(to, visited);
}
bool cut_vertex(const int &from, int size) {
  auto dup = visited;
  dup.set(from);
  for (const auto &to : edge[from]) {
    if (dup[to])
      continue;
    reachability(to, dup);
    return dup.count() != size;
  }
  return dup.count() != size;
}
bool dfs(const int &start, int from, int size) {
  unsigned long long m = visited.to_ullong() * N + from;
  if (memo.count(m))
    return false;
  memo.insert(m);
  if (cut_vertex(from, size))
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
  visited.set(from);
  for (const auto &to : edge[from]) {
    if (to == start && visited.count() == size)
      return true;
    if (visited[to])
      continue;
    if (dfs(start, to, size))
      return true;
  }
  visited.reset(from);
  return false;
}
bool solve(vector<vector<int>>& field) {
  visited = bitset<N>(0);
  make_graph(field);
  memo.clear();
  int size = vertex.size();
  for (int i = 0; i < size; ++i) {
    if (vertex[i] != -1)
      return dfs(vertex[i], vertex[i], size);
  }
  return false;
}
int main() {
  while (cin >> w >> h, w | h) {
    vector<vector<int>> field(h, vector<int>(w));
    for (auto &line : field)
      for (auto &v : line)
        cin >> v;
    cout << (solve(field) ? "Yes" : "No") << endl;
  }
}
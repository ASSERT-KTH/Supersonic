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
bitset<N> visited;
set<unsigned long long> memo;
int visited_count = 0;  // new variable to keep track of the number of visited nodes
map<int, bool> cut_vertex_cache;  // new map to cache the results of cut_vertex

void make_graph() {
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  size = 0;
  for (auto &v : vertex)
    fill(v.begin(), v.end(), NIL);
  for (auto &e : edge)
    e.clear();
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        vertex[y][x] = size++;
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
      }
    }
}

void reachability(const int &from, bitset<N> &visited) {
  visited.set(from);
  for (const auto &to : edge[from])
    if (!visited[to])
      reachability(to, visited);
}

bool cut_vertex(const int &from) {
  if (cut_vertex_cache.count(from))  // check if the result is cached
    return cut_vertex_cache[from];
  auto dup = visited;
  dup.set(from);
  for (const auto &to : edge[from]) {
    if (dup[to])
      continue;
    reachability(to, dup);
    return dup.count() != size;
  }
  bool result = dup.count() != size;
  cut_vertex_cache[from] = result;  // cache the result
  return result;
}

bool dfs(const int &start, int from) {
  unsigned long long m = visited.to_ullong() * N + from;
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
  visited.set(from);
  ++visited_count;  // increment the count of visited nodes
  for (const auto &to : edge[from]) {
    if (to == start && visited_count == size)
      return true;
    if (visited[to])
      continue;
    if (dfs(start, to))
      return true;
  }
  visited.reset(from);
  --visited_count;  // decrement the count of visited nodes
  return false;
}

bool solve() {
  visited.reset();
  visited_count = 0;  // reset the count of visited nodes
  make_graph();
  memo.clear();
  cut_vertex_cache.clear();  // clear the cache
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
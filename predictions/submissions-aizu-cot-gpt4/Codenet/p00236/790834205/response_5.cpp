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
unordered_map<int, bool> cut_vertex_memo;

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
}

void reachability(const int &from, bitset<N> &visited) {
  stack<int> st;
  st.push(from);
  while (!st.empty()) {
    int node = st.top();
    st.pop();
    visited.set(node);
    for (const auto &to : edge[node]) {
      if (!visited[to])
        st.push(to);
    }
  }
}

bool cut_vertex(const int &from) {
  if (cut_vertex_memo.count(from))
    return cut_vertex_memo[from];

  auto dup = visited;
  dup.set(from);
  for (const auto &to : edge[from]) {
    if (!dup[to]) {
      reachability(to, dup);
      if (dup.count() != size) {
        cut_vertex_memo[from] = true;
        return true;
      }
    }
  }
  cut_vertex_memo[from] = dup.count() != size;
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
    if (u != from && !visited[u]) {
      int degree = 0;
      for (const auto &v : edge[u])
        if (v == start || !visited[v])
          ++degree;
      if (degree < 2)
        return false;
    }
  }
  visited.set(from);
  for (const auto &to : edge[from]) {
    if (!visited[to] && (to == start && visited.count() == size || dfs(start, to)))
      return true;
  }
  visited.reset(from);
  return false;
}

bool solve() {
  visited.reset();
  make_graph();
  memo.clear();
  cut_vertex_memo.clear();
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
    cout << (solve() ? "Yes\n" : "No\n");
  }
}
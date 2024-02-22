#include <algorithm>
#include <bitset>
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
vector<vector<int>> field;
int size;
vector<vector<int>> vertex;
vector<vector<int>> edge;
bitset<N> visited;
unordered_set<unsigned long long> memo;
vector<int> degree;

void make_graph() {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  size = 0;
  vertex = vector<vector<int>>(h, vector<int>(w, NIL));
  degree = vector<int>(h * w, 0);
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
        ++degree[vertex[y][x]]; // calculate degree during graph construction
      }
    }
};
void reachability(const int &from, bitset<N> &visited) {
  stack<int> st;
  st.push(from);
  while (!st.empty()) {
    int v = st.top();
    st.pop();
    visited.set(v);
    for (const auto &to : edge[v]) {
      if (!visited[to])
        st.push(to);
    }
  }
}
bool cut_vertex(const int &from) {
  auto dup = visited;
  dup.set(from);
  reachability(from, dup);
  return dup.count() != size; // compute once and reuse
}
bool dfs(int start, int from) {
  stack<int> st;
  st.push(from);
  while (!st.empty()) {
    from = st.top();
    st.pop();
    unsigned long long m = visited.to_ullong() * N + from;
    if (memo.count(m))
      continue;
    memo.insert(m);
    if (cut_vertex(from))
      continue;
    for (int u = 0; u < size; ++u) {
      if (u == from)
        continue;
      if (visited[u])
        continue;
      if (degree[u] < 2) // use pre-calculated degree
        return false;
    }
    visited.set(from);
    for (const auto &to : edge[from]) {
      if (to == start && visited.count() == size)
        return true;
      if (visited[to])
        continue;
      st.push(to);
    }
  }
  return false;
}
bool solve() {
  visited = bitset<N>(0);
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
    make_graph(); // move graph construction to main
    cout << (solve() ? "Yes" : "No") << endl;
  }
}
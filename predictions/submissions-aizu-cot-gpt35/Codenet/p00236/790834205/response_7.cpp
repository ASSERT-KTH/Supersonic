#include <bitset>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
vector<vector<int>> vertex;
vector<vector<int>> edge;
bitset<N> visited;
set<unsigned long long> memo;

void make_graph() {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  vertex.clear();
  edge.clear();
  vertex.resize(h, vector<int>(w, NIL));
  visited.reset();
  int size = 0;
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      if (!field[y][x]) {
        vertex[y][x] = size++;
        visited.set(size - 1);
      }
    }
  }
  edge.resize(size, vector<int>());
  for (int y = 0; y < h; ++y) {
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
};

bool reachability(const int &from) {
  visited.set(from);
  vector<int> stack;
  stack.push_back(from);
  while (!stack.empty()) {
    int current = stack.back();
    stack.pop_back();
    for (const auto &to : edge[current]) {
      if (!visited[to]) {
        visited.set(to);
        stack.push_back(to);
      }
    }
  }
  return visited.count() == vertex.size();
}

bool dfs(const int &start, int from) {
  unsigned long long m = visited.to_ullong() * N + from;
  if (memo.count(m))
    return false;
  memo.insert(m);
  for (int u = 0; u < vertex.size(); ++u) {
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
    if (to == start && visited.count() == vertex.size())
      return true;
    if (visited[to])
      continue;
    if (dfs(start, to))
      return true;
  }
  visited.reset(from);
  return false;
}

bool solve() {
  make_graph();
  memo.clear();
  return dfs(0, 0);
}

int main() {
  while (cin >> w >> h, w | h) {
    cout << (solve() ? "Yes" : "No") << endl;
  }
}
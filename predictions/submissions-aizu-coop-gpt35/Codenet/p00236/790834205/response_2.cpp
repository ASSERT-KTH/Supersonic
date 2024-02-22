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
vector<vector<int>> adj;
bitset<N> visited;
bitset<N> reachable;
set<unsigned long long> memo;

void make_graph() {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  size = 0;
  adj.clear();
  adj.resize(h * w);
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      if (!field[y][x]) {
        int u = y * w + x;
        for (const auto &d : NEXT) {
          int ny = y + d[Y];
          int nx = x + d[X];
          if (ny < 0 || h <= ny || nx < 0 || w <= nx)
            continue;
          if (!field[ny][nx]) {
            int v = ny * w + nx;
            adj[u].push_back(v);
          }
        }
        size++;
      }
    }
  }
}

bool dfs(const int &start, int from) {
  unsigned long long m = visited.to_ullong() * N + from;
  if (memo.count(m))
    return false;
  memo.insert(m);
  if (reachable.count() != size)
    return false;
  int unvisitedNeighbors = 0;
  for (int i = 0; i < adj[from].size(); ++i) {
    int to = adj[from][i];
    if (to == start && reachable.count() == size)
      return true;
    if (!visited[to]) {
      unvisitedNeighbors++;
    }
  }
  if (unvisitedNeighbors < 2)
    return false;
  visited.set(from);
  for (int i = 0; i < adj[from].size(); ++i) {
    int to = adj[from][i];
    if (!visited[to]) {
      visited.set(to);
      reachable.set(to);
      if (dfs(start, to))
        return true;
      visited.reset(to);
      reachable.reset(to);
    }
  }
  visited.reset(from);
  return false;
}

bool solve() {
  visited.reset();
  reachable.reset();
  make_graph();
  memo.clear();
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      if (!field[y][x]) {
        int start = y * w + x;
        visited.set(start);
        reachable.set(start);
        if (dfs(start, start))
          return true;
        visited.reset(start);
        reachable.reset(start);
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  while (cin >> w >> h, w | h) {
    field.clear();
    field.resize(h, vector<int>(w));
    for (auto &line : field)
      for (auto &v : line)
        cin >> v;
    cout << (solve() ? "Yes" : "No") << endl;
  }
}
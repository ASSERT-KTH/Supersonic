#include <algorithm>
#include <bitset>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int N = 49;
int w, h;
vector<vector<int>> field(N, vector<int>(N));
int size;
vector<vector<int>> vertex(N, vector<int>(N));
vector<vector<int>> edge(N * N);
bitset<N> visited;
set<unsigned long long> memo;
int visitedCount = 0;
void make_graph() {
  // ... same code as before ...
}
void reachability(const int &from) {
  visited.set(from);
  ++visitedCount;
  for (const auto &to : edge[from])
    if (!visited[to])
      reachability(to);
}
bool cut_vertex(const int &from) {
  visited.set(from);
  ++visitedCount;
  for (const auto &to : edge[from]) {
    if (visited[to])
      continue;
    reachability(to);
    if (visitedCount != size) {
      visited.reset(from);
      --visitedCount;
      return true;
    }
  }
  if (visitedCount != size) {
    visited.reset(from);
    --visitedCount;
    return true;
  }
  visited.reset(from);
  --visitedCount;
  return false;
}
bool dfs(const int &start, int from) {
  // ... same code as before ...
}
bool solve() {
  visited.reset();
  visitedCount = 0;
  for (auto &vec : vertex)
    fill(vec.begin(), vec.end(), -1);
  for (auto &vec : edge)
    vec.clear();
  make_graph();
  memo.clear();
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        return dfs(vertex[y][x], vertex[y][x]);
  return false;
}
int main() {
  while (cin >> w >> h, w | h) {
    for (auto &line : field)
      for (auto &v : line)
        cin >> v;
    cout << (solve() ? "Yes" : "No") << endl;
  }
}
#include <iostream>
#include <vector>
#include <unordered_set>

const int N = 49;
int w, h;
std::vector<std::vector<int>> field;
int size;
std::vector<std::vector<int>> vertex;
std::vector<std::vector<int>> edge;
std::bitset<N> visited;
std::unordered_set<unsigned long long> memo;

void make_graph(std::vector<std::vector<int>>& vertex, std::vector<std::vector<int>>& edge) {
  enum { Y, X };
  const int NEXT[4][2] = { {0, 1}, {1, 0}, {-1, 0}, {0, -1} };
  const int NIL = -1;
  size = 0;
  vertex = std::vector<std::vector<int>>(h, std::vector<int>(w, NIL));
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        vertex[y][x] = size++;
  edge = std::vector<std::vector<int>>(h * w, std::vector<int>());
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x) {
      if (vertex[y][x] == NIL)
        continue;
      for (const auto& d : NEXT) {
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

void reachability(const int& from, std::bitset<N>& visited) {
  visited.set(from);
  for (const auto& to : edge[from])
    if (!visited[to])
      reachability(to, visited);
}

bool cut_vertex(const int& from) {
  auto dup = visited;
  dup.set(from);
  for (const auto& to : edge[from]) {
    if (dup[to])
      continue;
    reachability(to, dup);
    return dup.count() != size;
  }
  return dup.count() != size;
}

bool dfs(const int& start, int from) {
  unsigned long long m = visited.to_ullong() * N + from;
  if (memo.count(m))
    return false;
  memo.insert(m);
  if (cut_vertex(from))
    return false;

  std::vector<int> stack;
  stack.push_back(from);

  while (!stack.empty()) {
    int current = stack.back();
    stack.pop_back();

    if (visited[current])
      continue;
    visited.set(current);

    bool hasUnvisitedNeighbor = false;
    for (const auto& to : edge[current]) {
      if (to == start && visited.count() == size)
        return true;
      if (!visited[to]) {
        stack.push_back(to);
        hasUnvisitedNeighbor = true;
      }
    }

    if (!hasUnvisitedNeighbor)
      visited.reset(current);
  }

  return false;
}

bool solve() {
  visited.reset();
  make_graph(vertex, edge);
  memo.clear();
  for (int y = 0; y < h; ++y)
    for (int x = 0; x < w; ++x)
      if (!field[y][x])
        return dfs(vertex[y][x], vertex[y][x]);
  return false;
}

int main() {
  while (std::cin >> w >> h, w | h) {
    field = std::vector<std::vector<int>>(h, std::vector<int>(w));
    for (auto& line : field)
      for (auto& v : line)
        std::cin >> v;
    std::cout << (solve() ? "Yes" : "No") << std::endl;
  }
}
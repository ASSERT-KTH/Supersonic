#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

const int N = 49;

int w, h;
vector<vector<int>> field;
int size;
vector<vector<int>> vertex;
vector<vector<int>> edge;
vector<bool> visited;
unordered_set<unsigned long long> memo;

void make_graph(vector<vector<int>>& vertex, vector<vector<int>>& edge) {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  size = 0;
  vertex = vector<vector<int>>(h, vector<int>(w, NIL));
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      if (!field[y][x]) {
        vertex[y][x] = size++;
      }
    }
  }
  edge = vector<vector<int>>(h * w, vector<int>());
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      if (vertex[y][x] == NIL) {
        continue;
      }
      for (const auto &d : NEXT) {
        int ny = y + d[Y];
        int nx = x + d[X];
        if (ny < 0 || h <= ny || nx < 0 || w <= nx) {
          continue;
        }
        if (vertex[ny][nx] == NIL) {
          continue;
        }
        edge[vertex[y][x]].push_back(vertex[ny][nx]);
      }
    }
  }
}

void reachability(const vector<vector<int>>& edge, int from, vector<bool>& visited) {
  visited[from] = true;
  vector<int> stack;
  stack.push_back(from);
  while (!stack.empty()) {
    int current = stack.back();
    stack.pop_back();
    for (const auto& to : edge[current]) {
      if (!visited[to]) {
        visited[to] = true;
        stack.push_back(to);
      }
    }
  }
}

bool cut_vertex(const vector<vector<int>>& edge, int from, int size) {
  vector<bool> dup = visited;
  dup[from] = true;
  int count = 1;
  vector<int> stack;
  stack.push_back(from);
  while (!stack.empty()) {
    int current = stack.back();
    stack.pop_back();
    for (const auto& to : edge[current]) {
      if (!dup[to]) {
        dup[to] = true;
        stack.push_back(to);
        count++;
      }
    }
  }
  return count != size;
}

bool dfs(const vector<vector<int>>& edge, int start, int from) {
  unsigned long long m = 1ULL * visited.size() * N + from;
  if (memo.count(m)) {
    return false;
  }
  memo.insert(m);

  if (cut_vertex(edge, from, size)) {
    return false;
  }

  for (int u = 0; u < size; ++u) {
    if (visited[u] || u == from) {
      continue;
    }
    int degree = 0;
    for (const auto& v : edge[u]) {
      if (v == start || !visited[v]) {
        ++degree;
      }
    }
    if (degree < 2) {
      return false;
    }
  }

  visited[from] = true;
  for (const auto& to : edge[from]) {
    if (to == start && visited.size() - visited[from] == size - 1) {
      return true;
    }
    if (!visited[to] && dfs(edge, start, to)) {
      return true;
    }
  }
  visited[from] = false;
  return false;
}

bool solve() {
  make_graph(vertex, edge);
  memo.clear();
  visited = vector<bool>(size, false);
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      if (!field[y][x]) {
        return dfs(edge, vertex[y][x], vertex[y][x]);
      }
    }
  }
  return false;
}

int main() {
  while (cin >> w >> h, w | h) {
    field = vector<vector<int>>(h, vector<int>(w));
    for (auto& line : field) {
      for (auto& v : line) {
        cin >> v;
      }
    }
    cout << (solve() ? "Yes" : "No") << endl;
  }
}
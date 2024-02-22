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
vector<bool> visited;
set<unsigned long long> memo;

// Modified bitset implementation to support more vertices
struct Bitset {
  vector<unsigned long long> bits;
  int size;

  Bitset(int n) {
    size = (n + 63) / 64;
    bits.resize(size);
  }

  bool operator[](int i) const {
    int pos = i / 64;
    int bit = i % 64;
    return (bits[pos] >> bit) & 1;
  }

  void set(int i) {
    int pos = i / 64;
    int bit = i % 64;
    bits[pos] |= 1ULL << bit;
  }

  void reset(int i) {
    int pos = i / 64;
    int bit = i % 64;
    bits[pos] &= ~(1ULL << bit);
  }

  int count() const {
    int cnt = 0;
    for (int i = 0; i < size; ++i) {
      cnt += __builtin_popcountll(bits[i]);
    }
    return cnt;
  }
};

void make_graph() {
  enum { Y, X };
  const int NEXT[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
  const int NIL = -1;
  size = 0;
  vertex.resize(h * w, NIL);
  edge.resize(h * w);
  for (int y = 0; y < h; ++y) {
    for (int x = 0; x < w; ++x) {
      if (!field[y * w + x]) {
        vertex[y * w + x] = size++;
      }
      for (const auto& d : NEXT) {
        int ny = y + d[Y];
        int nx = x + d[X];
        if (ny < 0 || h <= ny || nx < 0 || w <= nx) {
          continue;
        }
        if (vertex[ny * w + nx] != NIL) {
          edge[vertex[y * w + x]].push_back(vertex[ny * w + nx]);
        }
      }
    }
  }
}

bool reachability(const int& from, Bitset& visited) {
  visited.set(from);
  bool connected = true;
  for (const auto& to : edge[from]) {
    if (!visited[to]) {
      connected &= reachability(to, visited);
    }
  }
  return connected;
}

bool cut_vertex(const int& from) {
  Bitset dup(size);
  dup.set(from);
  for (const auto& to : edge[from]) {
    if (dup[to]) {
      continue;
    }
    Bitset temp(size);
    temp.set(to);
    bool connected = reachability(to, temp);
    dup.bits |= temp.bits;
    if (!connected) {
      return true;
    }
  }
  return dup.count() != size;
}

bool dfs(const int& start, int from) {
  unsigned long long m = visited.count() * N + from;
  if (memo.count(m)) {
    return false;
  }
  memo.insert(m);
  if (cut_vertex(from)) {
    return false;
  }
  for (int u = 0; u < size; ++u) {
    if (u == from || visited[u]) {
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
  visited.set(from);
  for (const auto& to : edge[from]) {
    if (to == start && visited.count() == size) {
      return true;
    }
    if (!visited[to] && dfs(start, to)) {
      return true;
    }
  }
  visited.reset(from);
  return false;
}

bool solve() {
  visited.reset();
  make_graph();
  memo.clear();
  for (int i = 0; i < h * w; ++i) {
    if (!field[i]) {
      return dfs(vertex[i], vertex[i]);
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (cin >> w >> h, w | h) {
    field.resize(h * w);
    for (auto& v : field) {
      cin >> v;
    }
    cout << (solve() ? "Yes" : "No") << endl;
  }
  return 0;
}
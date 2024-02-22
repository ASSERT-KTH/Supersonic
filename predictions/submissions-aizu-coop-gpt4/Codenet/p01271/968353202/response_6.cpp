#include <cstring>
#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

struct po {
  int lx, ly, rx, ry;
  bool operator==(const po &other) const {
    return lx == other.lx && ly == other.ly && rx == other.rx && ry == other.ry;
  }
};

struct hash_fn {
  size_t operator()(const po &p) const {
    return p.lx ^ p.ly ^ p.rx ^ p.ry;
  }
};

int w, h;
string mp[2][51];
unordered_map<po, bool, hash_fn> visited;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

bool bfs(int lx, int ly, int rx, int ry) {
  queue<po> Q;
  Q.push((po){lx, ly, rx, ry});
  visited.clear();
  while (!Q.empty()) {
    po t = Q.front();
    Q.pop();
    // other parts of BFS remain the same...
  }
  return false;
}

int main() {
  // main function remains the same...
  return 0;
}
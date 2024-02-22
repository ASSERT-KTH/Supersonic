#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int color, parent, depth, top, goUp;
  bool visited;
};

int n;
vector<vector<int>> g;
vector<Node> nodes;

void decomp(int root) {
  queue<int> q;
  q.push(root);
  vector<int> tord;
  while (!q.empty()) {
    int v = q.front(); q.pop();
    nodes[v].visited = true;
    tord.push_back(v);
    for (int c : g[v]) {
      if (!nodes[c].visited) {
        q.push(c);
        nodes[c].parent = v;
        nodes[c].depth = nodes[v].depth + 1;
      }
    }
  }
  int c = 0;
  for (int u : tord) {
    if (nodes[u].visited)
      continue;
    q.push(u);
    while (!q.empty()) {
      int v = q.front(); q.pop();
      nodes[v].visited = true;
      nodes[v].color = c;
      nodes[v].goUp = nodes[u].parent;
      nodes[v].top = u;
      for (int c : g[v]) {
        if (!nodes[c].visited)
          q.push(c);
      }
    }
    c++;
  }
}

int solve(int u, int v) {
  while (nodes[u].color != nodes[v].color) {
    assert(u != -1 && v != -1);
    if (nodes[nodes[u].top].depth > nodes[nodes[v].top].depth)
      u = nodes[u].goUp;
    else
      v = nodes[v].goUp;
  }
  while (u != v) {
    assert(u != -1 && v != -1);
    if (nodes[u].depth > nodes[v].depth)
      u = nodes[u].parent;
    else
      v = nodes[v].parent;
  }
  return u;
}

int main() {
  cin >> n;
  g.assign(n, {});
  nodes = vector<Node>(n);
  for (int i = 0; i < n; i++) {
    int k;
    cin >> k;
    for (int j = 0; j < k; j++) {
      int c;
      cin >> c;
      g[i].push_back(c);
      nodes[c].parent = i;
    }
  }
  decomp(0);
  int q;
  cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    cin >> u >> v;
    cout << solve(u, v) << endl;
  }
}
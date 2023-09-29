#include <iostream>
#include <vector>
using namespace std;

enum Color {
  WHITE,
  GRAY,
  BLACK
};

struct Node {
  Color color = WHITE;
  int d = 0, f = 0;
  vector<int> edges;
};

vector<Node> graph;
int t = 0;

void search_loop(int i) {
  graph[i].d = ++t;
  graph[i].color = GRAY;
  for (int next : graph[i].edges) {
    if (graph[next].color == WHITE) {
      search_loop(next);
    }
  }
  graph[i].f = ++t;
  graph[i].color = BLACK;
}

void dfs() {
  t = 0;
  for (int i = 1; i < graph.size(); i++) {
    if (graph[i].color == WHITE)
      search_loop(i);
  }
  for (int i = 1; i < graph.size(); i++) {
    cout << i << " " << graph[i].d << " " << graph[i].f << endl;
  }
}

int main() {
  int n, i, j, e;
  cin >> n;
  graph.resize(n + 1);
  for (i = 1; i <= n; i++) {
    cin >> j >> e;
    graph[j].edges.resize(e);
    for (int& edge : graph[j].edges) {
      cin >> edge;
    }
  }
  dfs();
  return 0;
}
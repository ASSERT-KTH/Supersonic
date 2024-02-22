#include <iostream>
using namespace std;
#define WHITE 0
#define GRAY 1
#define BLACK 2

struct Node {
  int neighbor;
  Node* next;
};

Node* adjList[101];
int color[101];
int n;
int d[101], f[101], t;

void addEdge(int i, int k) {
  Node* newNode = new Node;
  newNode->neighbor = k;
  newNode->next = adjList[i];
  adjList[i] = newNode;
}

void search_loop(int i) {
  int next;
  d[i] = ++t;
  color[i] = GRAY;
  for (Node* neighbor = adjList[i]; neighbor != nullptr; neighbor = neighbor->next) {
    next = neighbor->neighbor;
    if (color[next] == WHITE) {
      search_loop(next);
    }
  }
  f[i] = ++t;
  color[i] = BLACK;
}

void dfs() {
  for (int i = 1; i <= n; i++)
    color[i] = WHITE;
  t = 0;
  for (int i = 1; i <= n; i++) {
    if (color[i] == WHITE)
      search_loop(i);
  }
  for (int i = 1; i <= n; i++) {
    cout << i << " " << d[i] << " " << f[i] << endl;
  }
}

int main() {
  int i, j, k, e;
  cin >> n;
  for (i = 1; i <= n; i++) {
    adjList[i] = nullptr;
  }
  do {
    cin >> i >> e;
    for (j = 1; j <= e; j++) {
      cin >> k;
      addEdge(i, k);
    }
  } while (i < n);
  dfs();
  cin >> n;
  return 0;
}
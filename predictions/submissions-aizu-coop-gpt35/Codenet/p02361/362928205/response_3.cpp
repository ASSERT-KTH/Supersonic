#include <cstdio>
#include <cstdlib>
using namespace std;

const int INF = 1000000000;
struct edge {
  int to, cost;
};

edge* G[100000];
int v, e, r;
int* d;
bool* visited;

struct PriorityQueue {
  int* heap;
  int* indices;
  int size;

  PriorityQueue(int n) {
    heap = new int[n];
    indices = new int[n];
    size = 0;
  }

  ~PriorityQueue() {
    delete[] heap;
    delete[] indices;
  }

  bool empty() {
    return size == 0;
  }

  void push(int v, int dist) {
    int i = indices[v];
    if (i == 0) {
      size++;
      i = size;
    }
    while (i != 1 && d[v] < d[heap[i / 2]]) {
      int parent = heap[i / 2];
      heap[i] = parent;
      indices[parent] = i;
      i /= 2;
    }
    heap[i] = v;
    indices[v] = i;
  }

  int top() {
    return heap[1];
  }

  void pop() {
    int v = heap[size];
    size--;
    int i = 1;
    while (i * 2 <= size) {
      int child = i * 2;
      if (child + 1 <= size && d[heap[child + 1]] < d[heap[child]]) {
        child++;
      }
      if (d[v] <= d[heap[child]]) {
        break;
      }
      heap[i] = heap[child];
      indices[heap[i]] = i;
      i = child;
    }
    heap[i] = v;
    indices[v] = i;
  }
};

void dijkstra() {
  PriorityQueue q(v);
  d[r] = 0;
  q.push(r, 0);
  while (!q.empty()) {
    int nv = q.top();
    q.pop();
    if (visited[nv]) {
      continue;
    }
    visited[nv] = true;
    for (int i = 0; i < e; i++) {
      int to = G[nv][i].to;
      int cost = G[nv][i].cost;
      if (visited[to]) {
        continue;
      }
      if (d[nv] + cost < d[to]) {
        d[to] = d[nv] + cost;
        q.push(to, d[to]);
      }
    }
  }
}

int main() {
  scanf("%d %d %d", &v, &e, &r);
  d = new int[v];
  visited = new bool[v];
  for (int i = 0; i < v; i++) {
    G[i] = new edge[e];
    d[i] = INF;
    visited[i] = false;
  }
  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    G[s][i].to = t;
    G[s][i].cost = d;
  }
  dijkstra();
  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      printf("INF\n");
    else
      printf("%d\n", d[i]);
  }
  for (int i = 0; i < v; i++) {
    delete[] G[i];
  }
  delete[] d;
  delete[] visited;
  return 0;
}
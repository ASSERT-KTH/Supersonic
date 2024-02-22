#include <cstdio>
#include <vector>
using namespace std;

const int INF = 1000000000;

struct edge {
  int to, cost;
};

vector<edge> G[100000];
int v, e, r;

class CustomPriorityQueue {
private:
  vector<pair<int, int>> heap;
  void heapify_up(int idx) {
    while (idx > 0 && heap[idx] < heap[(idx - 1) / 2]) {
      swap(heap[idx], heap[(idx - 1) / 2]);
      idx = (idx - 1) / 2;
    }
  }
  void heapify_down(int idx) {
    int n = heap.size();
    while (idx < n) {
      int left = idx * 2 + 1;
      int right = idx * 2 + 2;
      int smallest = idx;
      if (left < n && heap[left] < heap[smallest])
        smallest = left;
      if (right < n && heap[right] < heap[smallest])
        smallest = right;
      if (smallest == idx)
        break;
      swap(heap[idx], heap[smallest]);
      idx = smallest;
    }
  }

public:
  void push(pair<int, int> p) {
    heap.push_back(p);
    heapify_up(heap.size() - 1);
  }
  void pop() {
    heap[0] = heap.back();
    heap.pop_back();
    heapify_down(0);
  }
  pair<int, int> top() { return heap[0]; }
  bool empty() { return heap.empty(); }
};

int main() {
  std::ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> v >> e >> r;
  for (int i = 0; i < e; i++) {
    int s, t, d;
    cin >> s >> t >> d;
    edge tmp;
    tmp.to = t;
    tmp.cost = d;
    G[s].emplace_back(tmp);
  }
  vector<int> d(v, INF);
  d[r] = 0;

  CustomPriorityQueue q;
  q.push(make_pair(0, r));
  while (!q.empty()) {
    pair<int, int> p = q.top();
    q.pop();
    int nv = p.second;
    if (p.first > d[nv])
      continue;
    for (int i = 0; i < G[nv].size(); i++) {
      if (d[nv] + G[nv][i].cost < d[G[nv][i].to]) {
        d[G[nv][i].to] = d[nv] + G[nv][i].cost;
        q.push(make_pair(d[G[nv][i].to], G[nv][i].to));
      }
    }
  }

  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      puts("INF");
    else
      printf("%d\n", d[i]);
  }

  return 0;
}
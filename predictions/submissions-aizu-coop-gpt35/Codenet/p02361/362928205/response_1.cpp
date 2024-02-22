#include <algorithm>
#include <cstdio>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
const int INF = 1000000000;
struct edge {
  int to, cost;
};

int main() {
  int v, e, r;
  scanf("%d %d %d", &v, &e, &r);

  // Step 1: Reduce Memory Usage
  unordered_map<int, vector<edge>> graph;
  // Resize graph to match the number of vertices in the input
  graph.reserve(v);

  for (int i = 0; i < e; i++) {
    int s, t, d;
    scanf("%d %d %d", &s, &t, &d);
    edge tmp;
    tmp.to = t;
    tmp.cost = d;
    // Step 2: Improve Data Structure
    // Use unordered_map to directly access edges of each vertex
    graph[s].push_back(tmp);
  }

  vector<int> d(v, INF);
  d[r] = 0;
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
  q.push(make_pair(0, r));

  while (!q.empty()) {
    pair<int, int> p = q.top();
    q.pop();
    int nv = p.second;

    // Step 3: Avoid Unnecessary Computations
    // Remove the redundant check

    for (const auto &edge : graph[nv]) {
      if (d[nv] + edge.cost < d[edge.to]) {
        d[edge.to] = d[nv] + edge.cost;
        q.push(make_pair(d[edge.to], edge.to));
      }
    }
  }

  for (int i = 0; i < v; i++) {
    if (d[i] == INF)
      printf("INF\n");
    else
      printf("%d\n", d[i]);
  }
  return 0;
}
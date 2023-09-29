#include <iostream>
#include <vector>
#include <limits>
using namespace std;
const int MAX = 100000;
struct Edge {
  int source, target, weight;
};
vector<Edge> edges;
vector<int> distance(MAX);
int BellmanFord(int startVertex, int vertexCount, int edgeCount) {
  fill(distance.begin(), distance.end(), numeric_limits<int>::max());
  distance[startVertex] = 0;
  for (int v = 0; v < vertexCount - 1; ++v) {
    for (const auto &e : edges) {
      if (distance[e.source] != numeric_limits<int>::max() && distance[e.target] > distance[e.source] + e.weight) {
        distance[e.target] = distance[e.source] + e.weight;
        if (v == vertexCount - 2) {
          cout << "NEGATIVE CYCLE\n";
          return -1;
        }
      }
    }
  }
  for (int v = 0; v < vertexCount; ++v) {
    cout << (v ? " " : "") << (distance[v] == numeric_limits<int>::max() ? "INF" : to_string(distance[v]));
  }
  cout << '\n';
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int vertexCount, edgeCount;
  cin >> vertexCount >> edgeCount;
  edges.reserve(edgeCount);
  for (int i = 0; i < edgeCount; ++i) {
    int s, t, w;
    cin >> s >> t >> w;
    edges.push_back({s, t, w});
  }
  for (int v = 0; v < vertexCount; ++v) {
    if (BellmanFord(v, vertexCount, edgeCount) == -1) {
      break;
    }
  }
  return 0;
}
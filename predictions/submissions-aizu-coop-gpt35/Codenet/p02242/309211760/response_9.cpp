#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

static const int INFTY = (1 << 21);
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

typedef pair<int, int> pii; // pair of vertex and weight
typedef vector<pii> vii; // vector of pairs

void dijkstra() {
  int minv;
  vector<int> d(n, INFTY); // distance array
  vector<int> color(n, WHITE); // color array
  vector<vii> adjList(n); // adjacency list

  d[0] = 0;
  color[0] = GRAY;

  priority_queue<pii, vector<pii>, greater<pii>> pq; // min-heap
  pq.push(make_pair(0, 0)); // push source vertex with distance 0

  while (!pq.empty()) {
    pii u = pq.top(); // get vertex with minimum distance
    pq.pop();

    int uDist = u.first;
    int uVertex = u.second;

    if (d[uVertex] < uDist) {
      continue; // skip if already processed
    }

    color[uVertex] = BLACK;

    for (auto v : adjList[uVertex]) {
      int vVertex = v.first;
      int vWeight = v.second;

      if (d[vVertex] > d[uVertex] + vWeight) {
        d[vVertex] = d[uVertex] + vWeight;
        color[vVertex] = GRAY;
        pq.push(make_pair(d[vVertex], vVertex));
      }
    }
  }

  for (int i = 0; i < n; i++) {
    cout << i << " " << (d[i] == INFTY ? -1 : d[i]) << endl;
  }
}

int main() {
  int n;
  cin >> n;

  vector<vii> adjList(n); // adjacency list

  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;

    for (int j = 0; j < k; j++) {
      int v, c;
      cin >> v >> c;
      adjList[u].push_back(make_pair(v, c)); // add connection to adjacency list
    }
  }

  dijkstra();

  return 0;
}
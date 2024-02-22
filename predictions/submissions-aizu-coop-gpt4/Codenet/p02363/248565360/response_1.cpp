#include <iostream>
#include <vector>
#include <limits>
#define MAX 100000
using namespace std;

struct edge {
  int s, t, d;
};

void BellmanFord(int startVertex, int vNum, const vector<edge>& edges) {
  vector<int> d(MAX, numeric_limits<int>::max());
  d[startVertex] = 0;
  for (int i = 0; i < vNum - 1; ++i) {
    for (const auto& e : edges) {
      if (d[e.s] != numeric_limits<int>::max() && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
      }
    }
  }
  for (const auto& e : edges) {
    if (d[e.s] != numeric_limits<int>::max() && d[e.t] > d[e.s] + e.d) {
      cout << "NEGATIVE CYCLE" << endl;
      return;
    }
  }
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      cout << " ";
    if (d[i] == numeric_limits<int>::max()) {
      cout << "INF";
    } else
      cout << d[i];
  }
  cout << endl;
}

int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;
  vector<edge> edges(eNum);
  int s, t, w;
  for (int i = 0; i < eNum; ++i) {
    cin >> s >> t >> w;
    edges[i] = {s, t, w};
  }
  for (int i = 0; i < vNum; ++i) {
    BellmanFord(i, vNum, edges);
  }
}
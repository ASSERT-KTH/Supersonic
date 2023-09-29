#include <iostream>
#include <vector>
using namespace std;
#define MAX 100000
struct edge {
  int s, t, d;
};
vector<edge> edges;
int d[MAX];
bool BellmanFord(int startVertex, int vNum, int eNum) {
  fill(d, d + MAX, INT32_MAX);
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge &e = edges[j];
      if (d[e.s] != INT32_MAX && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
        if (i == vNum - 1) return false;
      }
    }
    if (!update) break;
  }
  return true;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int vNum, eNum;
  cin >> vNum >> eNum;
  int s, t, w;
  for (int i = 0; i < eNum; ++i) {
    cin >> s >> t >> w;
    edges.push_back({s, t, w});
  }
  for (int i = 0; i < vNum; ++i) {
    if (!BellmanFord(i, vNum, eNum)) {
      cout << "NEGATIVE CYCLE\n";
      return 0;
    }
    for (int j = 0; j < vNum; ++j) {
      if (j > 0) cout << " ";
      if (d[j] == INT32_MAX) cout << "INF";
      else cout << d[j];
    }
    cout << "\n";
  }
}
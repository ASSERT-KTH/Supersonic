#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>
using namespace std;
#define MAX 100000
struct edge {
  int s, t, d;
};
const vector<edge> edges;
ostringstream oss;
int d[MAX];
int BellmanFord(int startVertex, int vNum, int eNum) {
  fill(begin(d), end(d), __INT_MAX__);
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      const edge& e = edges[j];
      if (d[e.s] != __INT_MAX__ && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
        if (i == vNum - 1) {
          return -1;
        }
      }
    }
    if (!update)
      break;
  }
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      oss << " ";
    if (d[i] == __INT_MAX__) {
      oss << "INF";
    } else
      oss << d[i];
  }
  return 0;
}
int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;
  int s, t, w;
  for (int i = 0; i < eNum; ++i) {
    cin >> s >> t >> w;
    edges.push_back({s, t, w});
  }
  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      cout << "NEGATIVE CYCLE" << endl;
      return 0;
    }
    oss << "\n";
  }
  cout << oss.str();
}
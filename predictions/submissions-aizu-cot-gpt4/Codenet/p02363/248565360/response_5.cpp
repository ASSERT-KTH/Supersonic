#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 100000
struct edge {
  int s, t, d;
};
vector<edge> edges;
ostringstream ans; // change string to ostringstream
int d[MAX];
int BellmanFord(int startVertex, int vNum, int eNum) {
  fill((int *)d, (d + MAX), __INT_MAX__);
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge &e = edges[j]; // use reference to avoid copying
      if (d[e.s] != __INT_MAX__ && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
        if (i == vNum - 1) {
          cout << "NEGATIVE CYCLE" << endl;
          return -1;
        }
      }
    }
    if (!update)
      break;
  }
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ans << " "; // use output stream instead of append
    if (d[i] == __INT_MAX__) {
      ans << "INF";
    } else
      ans << d[i]; // use output stream instead of to_string
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
      return 0;
    }
    ans << "\n"; // use output stream instead of append
  }
  cout << ans.str(); // convert ostringstream to string
}
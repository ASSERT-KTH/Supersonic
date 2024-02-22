#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
#define MAX 100000
struct edge {
  int s, t, d;
};
string ans;
int d[MAX];
int BellmanFord(int startVertex, int vNum, int eNum, const vector<edge> &edges, stringstream &ans) {
  fill((int *)d, (d + MAX), __INT_MAX__);
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      const edge &e = edges[j];
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
      ans << " ";
    if (d[i] == __INT_MAX__) {
      ans << "INF";
    } else
      ans << d[i];
  }
  return 0;
}
int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;
  vector<edge> edges;
  int s, t, w;
  for (int i = 0; i < eNum; ++i) {
    cin >> s >> t >> w;
    edges.push_back({s, t, w});
  }
  stringstream ans;
  if (BellmanFord(0, vNum, eNum, edges, ans) == -1) {
    return 0;
  }
  cout << ans.str();
}
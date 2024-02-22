#include <iostream>
#include <string>
#include <limits.h>
#define MAX 100000
using namespace std;
struct edge {
  int s, t, d;
};
edge edges[MAX];
string ans;
int d[MAX];
int BellmanFord(int startVertex, int vNum, int eNum) {
  fill(d, d + vNum, INT_MAX);
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge e = edges[j];
      if (d[e.s] != INT_MAX && d[e.t] > d[e.s] + e.d) {
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
      ans.append(" ");
    if (d[i] == INT_MAX) {
      ans.append("INF");
    } else
      ans.append(to_string(d[i]));
  }
  return 0;
}
int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;
  for (int i = 0; i < eNum; ++i) {
    cin >> edges[i].s >> edges[i].t >> edges[i].d;
  }
  if (BellmanFord(0, vNum, eNum) == -1) {
    cout << "NEGATIVE CYCLE" << endl;
    return 0;
  }
  cout << ans << endl;
  return 0;
}
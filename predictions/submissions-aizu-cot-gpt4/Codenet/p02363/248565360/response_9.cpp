#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
using namespace std;
#define MAX 100000
struct edge {
  int s, t, d;
};
vector<edge> edges;
ostringstream ans;
int d[MAX];
int BellmanFord(int startVertex, int vNum, int eNum) {
  memset(d, 0x7f, sizeof(d)); // Optimize 1
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge &e = edges[j]; // Optimize 2
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
  ans << "\n"; // Optimize 4
  return 0;
}
int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;
  edges.resize(eNum);
  for (int i = 0; i < eNum; ++i) {
    cin >> edges[i].s >> edges[i].t >> edges[i].d; // Optimize 5
  }
  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
  }
  cout << ans.str();
}
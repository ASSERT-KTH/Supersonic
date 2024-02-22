#include <iostream>
#include <vector>
using namespace std;
#define MAX 100000

struct edge {
  int s, t, d;
};

int BellmanFord(int startVertex, int vNum, int eNum, edge* edges, int* d, string& ans) {
  fill(d, d + vNum, __INT_MAX__);
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge e = edges[j];
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
      ans.append(" ");
    if (d[i] == __INT_MAX__) {
      ans.append("INF");
    } else
      ans.append(to_string(d[i]));
  }
  return 0;
}

int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;

  edge* edges = new edge[eNum];
  for (int i = 0; i < eNum; ++i) {
    int s, t, w;
    cin >> s >> t >> w;
    edges[i] = {s, t, w};
  }

  int* d = new int[vNum];
  string ans;

  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum, edges, d, ans) == -1) {
      delete[] edges;
      delete[] d;
      return 0;
    }
    ans.append("\n");
  }

  cout << ans;

  delete[] edges;
  delete[] d;

  return 0;
}
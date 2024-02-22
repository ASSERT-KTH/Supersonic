#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
#define MAX 100000

struct edge {
  int s, t, d;
};

vector<edge> edges;

int BellmanFord(int startVertex, int vNum, int eNum, ostringstream &os) {
  int d[MAX];
  fill_n(d, MAX, __INT_MAX__);
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      const edge& e = edges[j];
      if (d[e.s] != __INT_MAX__ && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
        if (i == vNum - 1) {
          os << "NEGATIVE CYCLE" << endl;
          return -1;
        }
      }
    }
    if (!update)
      break;
  }
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      os << " ";
    if (d[i] == __INT_MAX__)
      os << "INF";
    else
      os << d[i];
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
  ostringstream os;
  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum, os) == -1) {
      cout << os.str();
      return 0;
    }
    os << "\n";
  }
  cout << os.str();
  return 0;
}
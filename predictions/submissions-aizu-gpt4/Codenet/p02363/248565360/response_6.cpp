#include <iostream>
#include <vector>
#include <limits>

using namespace std;

#define MAX 100000
struct edge {
  int s, t, d;
};
vector<edge> edges;
int d[MAX];

int BellmanFord(int startVertex, int vNum, int eNum) {
  fill(d, d + MAX, numeric_limits<int>::max());
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge& e = edges[j];
      if (d[e.s] != numeric_limits<int>::max() && d[e.t] > d[e.s] + e.d) {
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
      cout << " ";
    if (d[i] == numeric_limits<int>::max()) {
      cout << "INF";
    } else
      cout << d[i];
  }
  cout << "\n";
  return 0;
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
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
  }
}
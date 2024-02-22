#include <iostream>
#include <vector>
#include <sstream>
#include <limits>
using namespace std;

struct edge {
  int s, t, d;
};

vector<edge> edges;
stringstream ans;
vector<int> d;

int BellmanFord(int startVertex, int vNum, int eNum) {
  d.assign(vNum, numeric_limits<int>::max());
  d[startVertex] = 0;

  bool update = true;
  for (int i = 0; i < vNum && update; ++i) {
    update = false;
    for (const edge& e : edges) {
      if (d[e.s] != numeric_limits<int>::max() && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
        if (i == vNum - 1) {
          cout << "NEGATIVE CYCLE" << endl;
          return -1;
        }
      }
    }
  }

  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ans << " ";
    if (d[i] == numeric_limits<int>::max()) {
      ans << "INF";
    } else {
      ans << d[i];
    }
  }

  return 0;
}

int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;
  int s, t, w;

  edges.reserve(eNum);

  for (int i = 0; i < eNum; ++i) {
    cin >> s >> t >> w;
    edges.push_back({s, t, w});
  }

  ans.str("");
  ans.clear();

  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
    ans << "\n";
  }

  cout << ans.str();
}
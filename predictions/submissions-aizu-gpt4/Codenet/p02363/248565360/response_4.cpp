#include <iostream>
#include <vector>
#include <limits>
#include <string>
using namespace std;

const int MAX = 100000;
struct edge {
  int s, t, d;
};

vector<edge> edges(MAX);
vector<int> d(MAX);
string ans;

int BellmanFord(int startVertex, int vNum, int eNum) {
  fill(d.begin(), d.begin() + vNum, numeric_limits<int>::max());
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge &e = edges[j];
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
      ans.push_back(' ');
    if (d[i] == numeric_limits<int>::max()) {
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
  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
    ans.push_back('\n');
  }
  cout << ans;
}
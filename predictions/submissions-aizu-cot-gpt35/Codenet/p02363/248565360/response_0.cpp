#include <iostream>
#include <vector>
#include <sstream>
using namespace std;

#define MAX 100000

struct edge {
  int s, t, d;
};

vector<edge> edges;
string ans;
long long d[MAX];

int BellmanFord(int startVertex, int vNum, int eNum) {
  fill(d, d + MAX, LLONG_MAX);
  d[startVertex] = 0;

  for (int i = 0; i < vNum; ++i) {
    for (int j = 0; j < eNum; ++j) {
      edge e = edges[j];
      if (d[e.s] != LLONG_MAX && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        if (i == vNum - 1) {
          cout << "NEGATIVE CYCLE" << endl;
          return -1;
        }
      }
    }
  }

  stringstream ss;
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ss << " ";
    if (d[i] == LLONG_MAX) {
      ss << "INF";
    } else {
      ss << d[i];
    }
  }

  ans = ss.str();
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

  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
    ans.append("\n");
  }

  cout << ans;
}
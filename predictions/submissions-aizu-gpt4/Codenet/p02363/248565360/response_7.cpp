#include <iostream>
#include <vector>
#include <limits>
using namespace std;
#define MAX 100000
struct edge {
  int s, t, d;
};
vector<edge> edges;
vector<int> d(MAX);
vector<string> ans;
int BellmanFord(int startVertex, int vNum, int eNum) {
  fill(d.begin(), d.end(), numeric_limits<int>::max());
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge &e = edges[j];
      if (d[e.s] != numeric_limits<int>::max() && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
        if (i == vNum - 1) {
          ans.emplace_back("NEGATIVE CYCLE");
          return -1;
        }
      }
    }
    if (!update)
      break;
  }
  string line;
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      line += ' ';
    if (d[i] == numeric_limits<int>::max()) {
      line += "INF";
    } else
      line += to_string(d[i]);
  }
  ans.emplace_back(move(line));
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
      break;
    }
  }
  for (const string &line : ans) {
    cout << line << '\n';
  }
}
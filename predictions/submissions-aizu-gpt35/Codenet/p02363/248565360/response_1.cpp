#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 100000
struct edge {
  int s, t, d;
};
vector<edge> edges;
string ans;
int d[MAX];
int BellmanFord(int startVertex, int vNum, int eNum) {
  fill(d, d + vNum, __INT_MAX__);
  d[startVertex] = 0;
  for (int i = 0; i < vNum - 1; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge e = edges[j];
      if (d[e.s] != __INT_MAX__ && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
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
  for (int j = 0; j < eNum; ++j) {
    edge e = edges[j];
    if (d[e.s] != __INT_MAX__ && d[e.t] > d[e.s] + e.d) {
      cout << "NEGATIVE CYCLE" << endl;
      return -1;
    }
  }
  return 0;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
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
    ans.append("\n");
  }
  cout << ans;
}
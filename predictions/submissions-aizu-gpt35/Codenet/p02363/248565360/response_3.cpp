#include <iostream>
#include <string>
#include <vector>
#include <limits> // include limits header to use INT_MAX
using namespace std;

struct edge {
  int s, t, d;
};

vector<edge> edges;
string ans;
vector<int> d; // Use vector instead of array for dynamic memory allocation

int BellmanFord(int startVertex, int vNum, int eNum) {
  d.assign(vNum, INT_MAX); // assign INT_MAX to all elements of vector d
  d[startVertex] = 0;
  for (int i = 0; i < vNum - 1; ++i) { // optimization: run loop for vNum-1 times only
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge e = edges[j];
      if (d[e.s] != INT_MAX && d[e.t] > d[e.s] + e.d) {
        d[e.t] = d[e.s] + e.d;
        update = true;
      }
    }
    if (!update) { // optimization: if no update happens in this iteration, break the loop
      break;
    }
  }
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ans.append(" ");
    if (d[i] == INT_MAX) {
      ans.append("INF");
    } else
      ans.append(to_string(d[i]));
  }
  for (int j = 0; j < eNum; ++j) { // check for negative cycles separately after the vNum-1 iterations
    edge e = edges[j];
    if (d[e.s] != INT_MAX && d[e.t] > d[e.s] + e.d) {
      cout << "NEGATIVE CYCLE" << endl;
      return -1;
    }
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
  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
    ans.append("\n");
  }
  cout << ans;
}
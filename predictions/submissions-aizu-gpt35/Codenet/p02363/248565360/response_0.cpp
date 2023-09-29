#include <iostream>
#include <string>
#include <vector>
#include <cstring> // Added for memset
using namespace std;
#define MAX 100000
struct edge {
  int s, t, d;
};
vector<edge> edges;
string ans;
int d[MAX];
int BellmanFord(int startVertex, int vNum, int eNum) {
  memset(d, 0x3f, sizeof(d)); // Replaced fill with memset
  d[startVertex] = 0;
  for (int i = 0; i < vNum - 1; ++i) { // Removed unnecessary check for i == vNum - 1
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      edge e = edges[j];
      if (d[e.s] != 0x3f3f3f3f && d[e.t] > d[e.s] + e.d) { // Replaced __INT_MAX__ with 0x3f3f3f3f
        d[e.t] = d[e.s] + e.d;
        update = true;
      }
    }
    if (!update)
      break;
  }
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ans += " "; // Replaced append with +=
    if (d[i] == 0x3f3f3f3f) { // Replaced __INT_MAX__ with 0x3f3f3f3f
      ans += "INF"; // Replaced append with +=
    } else
      ans += to_string(d[i]); // Replaced append with +=
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
    ans += "\n"; // Replaced append with +=
  }
  cout << ans;
}
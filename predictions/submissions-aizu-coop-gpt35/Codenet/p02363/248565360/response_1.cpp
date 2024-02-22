#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;
#define MAX 100000

struct edge {
  int t, d;
};

vector<vector<edge>> adjList;
string ans;

void BellmanFord(int startVertex, int vNum) {
  vector<int> d(vNum, __INT_MAX__);
  d[startVertex] = 0;

  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < adjList[i].size(); ++j) {
      edge e = adjList[i][j];
      if (d[i] != __INT_MAX__ && d[e.t] > d[i] + e.d) {
        d[e.t] = d[i] + e.d;
        update = true;
        if (i == vNum - 1) {
          cout << "NEGATIVE CYCLE" << endl;
          return;
        }
      }
    }
    if (!update)
      break;
  }

  stringstream ss;
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ss << " ";
    if (d[i] == __INT_MAX__) {
      ss << "INF";
    } else {
      ss << d[i];
    }
  }
  ans = ss.str();
}

int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;

  adjList.resize(vNum);

  int s, t, w;
  for (int i = 0; i < eNum; ++i) {
    cin >> s >> t >> w;
    adjList[s].push_back({t, w});
  }

  stringstream ss;
  for (int i = 0; i < vNum; ++i) {
    BellmanFord(i, vNum);
    ss << ans << "\n";
  }

  cout << ss.str();

  return 0;
}
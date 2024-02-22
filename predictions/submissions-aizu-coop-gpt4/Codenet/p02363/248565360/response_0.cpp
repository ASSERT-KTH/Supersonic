#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
#define MAX 100000

vector<vector<pair<int,int>>> adjList(MAX);

int BellmanFord(int startVertex, int vNum) {
  vector<int> d(MAX, INT_MAX);
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (auto &edge : adjList[startVertex]) {
      int v = edge.first, w = edge.second;
      if (d[v] > d[startVertex] + w) {
        d[v] = d[startVertex] + w;
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
    if (d[i] == INT_MAX) {
      cout << "INF";
    } else
      cout << d[i];
  }
  cout << endl;
  return 0;
}

int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;
  int s, t, w;
  for (int i = 0; i < eNum; ++i) {
    cin >> s >> t >> w;
    adjList[s].push_back({t, w});
  }
  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum) == -1) {
      return 0;
    }
  }
}
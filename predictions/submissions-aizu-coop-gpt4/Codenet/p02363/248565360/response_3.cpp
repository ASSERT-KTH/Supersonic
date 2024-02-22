#include <iostream>
#include <vector>
#include <list>
#define MAX 100000

using namespace std;

struct edge {
  int t, d;
};

vector<list<edge>> adjList(MAX);
int d[MAX];

int BellmanFord(int startVertex, int vNum, int eNum) {
  for(int i=0; i<MAX; i++)
    d[i] = INT_MAX;

  d[startVertex] = 0;

  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < vNum; ++j) {
      for(auto& e: adjList[j]) {
        if (d[j] != INT_MAX && d[e.t] > d[j] + e.d) {
          d[e.t] = d[j] + e.d;
          update = true;
          if (i == vNum - 1) {
            cout << "NEGATIVE CYCLE" << endl;
            return -1;
          }
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
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
  }

  return 0;
}
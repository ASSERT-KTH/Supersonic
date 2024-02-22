#include <iostream>
#include <string>
#include <vector>
using namespace std;
#define MAX 100000
#define INF __INT_MAX__
int graph[MAX][MAX];
int d[MAX];
void BellmanFord(int startVertex, int vNum) {
  for(int i = 0; i < vNum; i++)
    d[i] = INF;
  d[startVertex] = 0;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < vNum; ++j) {
      for (int k = 0; k < vNum; ++k) {
        if (graph[j][k] != INF && d[j] != INF && d[k] > d[j] + graph[j][k]) {
          d[k] = d[j] + graph[j][k];
          update = true;
          if (i == vNum - 1) {
            cout << "NEGATIVE CYCLE" << endl;
            return;
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
    if (d[i] == INF) {
      cout << "INF";
    } else
      cout << d[i];
  }
  cout << endl;
}
int main() {
  int vNum, eNum;
  cin >> vNum >> eNum;
  int s, t, w;
  for(int i = 0; i < vNum; i++)
    for(int j = 0; j < vNum; j++)
      graph[i][j] = i == j ? 0 : INF;
  for (int i = 0; i < eNum; ++i) {
    cin >> s >> t >> w;
    graph[s][t] = w;
  }
  for (int i = 0; i < vNum; ++i) {
    BellmanFord(i, vNum);
  }
}
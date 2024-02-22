#include <iostream>
#include <string>
#include <climits>
using namespace std;

#define MAX 100000

int graph[MAX][MAX];
string ans;
int d[MAX];

int BellmanFord(int startVertex, int vNum, int eNum) {
  for (int i = 0; i < vNum; ++i) {
    d[i] = (i == startVertex) ? 0 : INT_MAX/2;
  }

  bool hasNegativeCycle = false;
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    for (int j = 0; j < eNum; ++j) {
      int s = graph[j][0];
      int t = graph[j][1];
      int w = graph[j][2];

      if (d[s] != INT_MAX/2 && d[t] > d[s] + w) {
        d[t] = d[s] + w;
        update = true;
        if (i == vNum - 1) {
          hasNegativeCycle = true;
          break;
        }
      }
    }
    if (!update)
      break;
  }

  if (hasNegativeCycle) {
    cout << "NEGATIVE CYCLE" << endl;
    return -1;
  }

  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      ans.append(" ");
    if (d[i] == INT_MAX/2) {
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
    int s, t, w;
    cin >> s >> t >> w;
    graph[i][0] = s;
    graph[i][1] = t;
    graph[i][2] = w;
  }

  for (int i = 0; i < vNum; ++i) {
    if (BellmanFord(i, vNum, eNum) == -1) {
      return 0;
    }
    ans.append("\n");
  }

  cout << ans;
}
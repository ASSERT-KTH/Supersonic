#include <iostream>
#include <sstream>
#include <vector>
#include <list>
using namespace std;

#define MAX 100000

struct edge {
  int t, d;
};

list<edge> adjList[MAX];
string ans;
int d[MAX];

int BellmanFord(int startVertex, int vNum) {
  fill((int *)d, (d + MAX), __INT_MAX__);
  d[startVertex] = 0;
  
  for (int i = 0; i < vNum; ++i) {
    bool update = false;
    
    for (const edge& e : adjList[startVertex]) {
      if (d[startVertex] != __INT_MAX__ && d[e.t] > d[startVertex] + e.d) {
        d[e.t] = d[startVertex] + e.d;
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
  
  ostringstream oss;
  for (int i = 0; i < vNum; ++i) {
    if (i > 0)
      oss << " ";
      
    if (d[i] == __INT_MAX__) {
      oss << "INF";
    } else
      oss << d[i];
  }
  
  ans += oss.str();
  
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
    ans += "\n";
  }
  
  cout << ans;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAX_N = 110000;
const int MAX_M = 210000;

int n, m, q, a[MAX_M], b[MAX_M], c, dist[MAX_N], T[MAX_N], cnt, U[MAX_N];
vector<pair<int, int>> x[MAX_N], y[MAX_N];
bool used[MAX_M];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  cin >> n >> m >> q;
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    x[a[i]].push_back(make_pair(b[i], i));
    x[b[i]].push_back(make_pair(a[i], i));
  }
  
  fill(dist, dist + n + 1, 999999);
  dist[1] = 0;
  deque<int> Q;
  Q.push_back(1);
  
  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop_front();
    
    for (pair<int, int> i : x[a1]) {
      if (dist[i.first] > dist[a1] + 1) {
        dist[i.first] = dist[a1] + 1;
        Q.push_back(i.first);
      }
    }
  }
  
  for (int i = 1; i < n; i++) {
    for (pair<int, int> j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].push_back(j);
        T[j.first]++;
      }
    }
  }
  
  for (int i = 0; i < q; i++) {
    cin >> c;
    c--;
    deque<pair<int, int>> Q1;
    int ss = -1;
    if (dist[a[c]] != dist[b[c]]) {
      ss = (dist[a[c]] < dist[b[c]]) ? b[c] : a[c];
    }
    
    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      Q1.push_back(make_pair(ss, c));
      
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop_front();
        
        if (U[a1] == 1 || used[a2] == true) {
          continue;
        }
        
        T[a1]--;
        used[a2] = true;
        
        if (T[a1] != 0) {
          continue;
        }
        
        cnt++;
        U[a1] = 1;
        
        for (pair<int, int> j : y[a1]) {
          if (U[j.first] == 0) {
            Q1.push_back(j);
          }
        }
      }
    }
    
    cout << cnt << endl;
  }
  
  return 0;
}
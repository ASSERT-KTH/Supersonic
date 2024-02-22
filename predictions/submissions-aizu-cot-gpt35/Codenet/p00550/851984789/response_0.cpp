#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
using namespace std;

int main() {
  int n, m, q;
  cin >> n >> m >> q;
  
  unordered_map<int, vector<pair<int, int>>> x, y;
  vector<int> a(m), b(m), dist(n + 1, 999999), T(n + 1), U(n + 1);
  vector<bool> used(m);
  
  for (int i = 0; i < m; i++) {
    cin >> a[i] >> b[i];
    x[a[i]].emplace_back(b[i], i);
    x[b[i]].emplace_back(a[i], i);
  }
  
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
  
  for (int i = 1; i <= n; i++) {
    for (pair<int, int> j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].emplace_back(j);
        T[j.first]++;
      }
    }
  }
  
  int cnt = 0;
  
  for (int i = 0; i < q; i++) {
    int c;
    cin >> c;
    c--;
    deque<pair<int, int>> Q1;
    int ss = -1;
    
    if (dist[a[c]] < dist[b[c]])
      ss = b[c];
    if (dist[a[c]] > dist[b[c]])
      ss = a[c];
    
    if (ss >= 1 && U[ss] == 0 && !used[c]) {
      Q1.emplace_back(ss, c);
      
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop_front();
        
        if (U[a1] == 1 || used[a2])
          continue;
        
        T[a1]--;
        used[a2] = true;
        
        if (T[a1] != 0)
          continue;
        
        cnt++;
        U[a1] = 1;
        
        for (pair<int, int> j : y[a1]) {
          if (U[j.first] == 0)
            Q1.emplace_back(j);
        }
      }
    }
    
    cout << cnt << endl;
  }
  
  return 0;
}
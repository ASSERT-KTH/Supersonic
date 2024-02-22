#include <bits/stdc++.h>
using namespace std;
int n, m, q, a[210000], b[210000], c, dist[110000], T[110000], cnt, U[110000];
vector<pair<int, int>> x[110000], y[110000];
bool used[210000];
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    x[a[i]].push_back(make_pair(b[i], i));
    x[b[i]].push_back(make_pair(a[i], i));
  }
  fill(dist, dist + n + 1, 999999);
  dist[1] = 0;
  deque<int> Q;  // Use deque instead of queue
  Q.push_back(1);  // Use push_back instead of push
  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop_front();  // Use pop_front instead of pop
    for (auto& i : x[a1]) {  // Use range-based for loop
      if (dist[i.first] > dist[a1] + 1) {
        dist[i.first] = dist[a1] + 1;
        Q.push_back(i.first);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (auto& j : x[i]) {  // Use range-based for loop
      if (dist[i] < dist[j.first]) {
        y[i].push_back(j);
        T[j.first]++;
      }
    }
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", &c);
    c--;
    deque<pair<int, int>> Q1;  // Use deque instead of queue
    int ss = -1;
    if (dist[a[c]] < dist[b[c]])
      ss = b[c];
    if (dist[a[c]] > dist[b[c]])
      ss = a[c];
    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      Q1.push_back(make_pair(ss, c));  // Use push_back instead of push
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop_front();  // Use pop_front instead of pop
        if (U[a1] == 1 || used[a2] == true)
          continue;
        T[a1]--;
        used[a2] = true;
        if (T[a1] != 0)
          continue;
        cnt++;
        U[a1] = 1;
        for (auto& j : y[a1]) {  // Use range-based for loop
          if (U[j.first] == 0)
            Q1.push_back(j);
        }
      }
    }
    cout << cnt << "\n";
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int n, m, q, a[210000], b[210000], c, dist[110000], T[110000], cnt, U[110000];
vector<pair<int, int>> x[110000], y[110000];
bool used[210000];

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  scanf("%d%d%d", &n, &m, &q);
  pair<int, int> temp_pair;
  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    temp_pair.first = b[i];
    temp_pair.second = i;
    x[a[i]].push_back(temp_pair);
    temp_pair.first = a[i];
    x[b[i]].push_back(temp_pair);
  }
  
  fill(dist, dist + n + 1, 999999);
  dist[1] = 0;
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop();
    for (const auto& i : x[a1]) {
      if (dist[i.first] > dist[a1] + 1) {
        dist[i.first] = dist[a1] + 1;
        Q.push(i.first);
      }
    }
  }
  
  for (int i = 1; i <= n; i++) {
    for (const auto& j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].push_back(j);
        T[j.first]++;
      }
    }
  }
  
  queue<pair<int, int>> Q1;
  for (int i = 0; i < q; i++) {
    scanf("%d", &c);
    c--;
    int ss = -1;
    if (dist[a[c]] < dist[b[c]]) ss = b[c];
    if (dist[a[c]] > dist[b[c]]) ss = a[c];
    if (ss >= 1 && U[ss] == 0 && used[c] == false) Q1.push(make_pair(ss, c));
    while (!Q1.empty()) {
      int a1 = Q1.front().first, a2 = Q1.front().second;
      Q1.pop();
      if (U[a1] == 1 || used[a2] == true) continue;
      T[a1]--;
      used[a2] = true;
      if (T[a1] != 0) continue;
      cnt++;
      U[a1] = 1;
      for (const auto& j : y[a1]) {
        if (U[j.first] == 0) Q1.push(j);
      }
    }
    cout << cnt << endl;
  }
  return 0;
}
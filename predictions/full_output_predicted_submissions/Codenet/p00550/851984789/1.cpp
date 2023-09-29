#include <bits/stdc++.h>
using namespace std;
int n, m, q, a[210000], b[210000], c, dist[110000], T[110000];
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
  queue<int> Q;
  Q.push(1);
  while (!Q.empty()) {
    int a1 = Q.front();
    Q.pop();
    for (pair<int, int> i : x[a1]) {
      if (dist[i.first] > dist[a1] + 1) {
        dist[i.first] = dist[a1] + 1;
        Q.push(i.first);
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (pair<int, int> j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].push_back(j);
        T[j.first]++;
      }
    }
  }
  for (int i = 0; i < q; i++) {
    scanf("%d", &c);
    c--;
    queue<pair<int, int>> q;

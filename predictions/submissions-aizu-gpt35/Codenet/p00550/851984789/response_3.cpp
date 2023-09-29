#include <bits/stdc++.h>
using namespace std;
const int MAXN = 110000;
int n, m, q, cnt;
int dist[MAXN], T[MAXN], U[MAXN];
vector<pair<int, int>> x[MAXN], y[MAXN];
bool used[MAXN];
void bfs() {
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
}
void process() {
  for (int i = 1; i <= n; i++) {
    for (pair<int, int> j : x[i]) {
      if (dist[i] < dist[j.first]) {
        y[i].push_back(j);
        T[j.first]++;
      }
    }
  }
}
void solve() {
  for (int i = 0; i < q; i++) {
    int c;
    scanf("%d", &c);
    c--;
    queue<pair<int, int>> Q1;
    int ss = -1;
    if (dist[x[c][0].first] < dist[x[c][1].first])
      ss = x[c][1].first;
    if (dist[x[c][0].first] > dist[x[c][1].first])
      ss = x[c][0].first;
    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      Q1.push(make_pair(ss, c));
      while (!Q1.empty()) {
        int a1 = Q1.front().first, a2 = Q1.front().second;
        Q1.pop();
        if (U[a1] == 1 || used[a2] == true)
          continue;
        T[a1]--;
        used[a2] = true;
        if (T[a1] != 0)
          continue;
        cnt++;
        U[a1] = 1;
        for (pair<int, int> j : y[a1]) {
          if (U[j.first] == 0)
            Q1.push(j);
        }
      }
    }
    printf("%d\n", cnt);
  }
}
int main() {
  scanf("%d%d%d", &n, &m, &q);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    x[a].push_back(make_pair(b, i));
    x[b].push_back(make_pair(a, i));
  }
  bfs();
  process();
  solve();
  return 0;
}
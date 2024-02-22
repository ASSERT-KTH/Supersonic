#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

const int MAX_N = 110000;
const int MAX_M = 210000;

int n, m, q, c, cnt;
int a[MAX_M], b[MAX_M], dist[MAX_N], T[MAX_N], U[MAX_N];
vector<pair<int, int>> x[MAX_N], y[MAX_N];
vector<bool> used(MAX_M, false);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  scanf("%d%d%d", &n, &m, &q);

  for (int i = 0; i < m; i++) {
    scanf("%d%d", &a[i], &b[i]);
    x[a[i]].emplace_back(b[i], i);
    x[b[i]].emplace_back(a[i], i);
  }

  memset(dist, 127, sizeof(dist));
  dist[1] = 0;

  vector<int> Q(1, 1);

  for (int i = 0; i < Q.size(); i++) {
    int a1 = Q[i];
    for (pair<int, int> j : x[a1]) {
      if (dist[j.first] > dist[a1] + 1) {
        dist[j.first] = dist[a1] + 1;
        Q.push_back(j.first);
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
    vector<pair<int, int>> Q1;
    int ss = -1;
    if (dist[a[c]] < dist[b[c]])
      ss = b[c];
    if (dist[a[c]] > dist[b[c]])
      ss = a[c];
    if (ss >= 1 && U[ss] == 0 && used[c] == false) {
      Q1.emplace_back(ss, c);
      while (!Q1.empty()) {
        int a1 = Q1.back().first, a2 = Q1.back().second;
        Q1.pop_back();
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
            Q1.emplace_back(j);
        }
      }
    }
    printf("%d\n", cnt);
  }

  return 0;
}
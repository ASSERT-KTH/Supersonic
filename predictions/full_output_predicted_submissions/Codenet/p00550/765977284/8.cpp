#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
void reader(int *x) {
  int k = getchar_unlocked();
  *x = k - '0';
  while (1) {
    k = getchar_unlocked();
    if (k < '0' || k > '9')
      break;
    *x = ((*x) << 1) + ((*x) << 3) + k - '0';
  }
}
vector<int> E[100000];
int u[200000], v[200000], r[200000], ans[200000], d[100000], cnt = 1;
bool b[100000];
queue<int> que;
void bfs(int u, int t) {
  que.push(u);
  while (!que.empty()) {
    int p = que.front();
    que.pop();
    for (int v : E[p]) {
      if (t) {
        if (d[v] > d[p] && !ok[v]) {
          ok[v] = 1;
          cnt++;
          que.push(v);
        }
      } else if (!~d[v]) {
        d[v] = d[p] + 1;
        que.push(v);
      }
    }
  }
}
int main() {
  int n, m, q;
  reader(&n);
  reader(&m);
  reader(&q);
  rep(i, m) {
    reader(&u[i]);
    reader(&v[i]);
    u[i]--;
    v[i]--;
    E[u[i]]--
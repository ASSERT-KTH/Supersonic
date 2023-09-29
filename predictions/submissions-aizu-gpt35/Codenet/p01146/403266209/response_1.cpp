#include <bits/stdc++.h>
#define r(i, n) for (int i = 0; i < n; i++)
#define INF 1e9
using namespace std;

const int MAXN = 205;

int n, m, l, k, a, h, t1, t2, t3;
int b[MAXN][MAXN], x[MAXN][MAXN];
set<int> rei;

void floyd(int g[MAXN][MAXN]) {
  r(o, n) r(i, n) r(j, n) g[i][j] = min(g[i][j], g[i][o] + g[o][j]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (cin >> n, n) {
    cin >> m >> l >> k >> a >> h;
    rei.clear();
    rei.insert(a), rei.insert(h);
    r(i, l) {
      int re;
      cin >> re;
      rei.insert(re);
    }
    r(i, n) r(j, n) x[i][j] = b[i][j] = INF;
    r(i, k) {
      cin >> t1 >> t2 >> t3;
      b[t1][t2] = b[t2][t1] = t3;
    }
    floyd(b);
    r(i, n) {
      if (rei.count(i)) {
        r(j, n) {
          if (rei.count(j) && b[i][j] <= m) {
            x[i][j] = b[i][j];
          }
        }
      }
    }
    floyd(x);
    if (x[a][h] >= INF) {
      cout << "Help!" << endl;
    } else if (x[a][h] < m) {
      cout << x[a][h] << endl;
    } else {
      cout << x[a][h] * 2 - m << endl;
    }
  }
  return 0;
}
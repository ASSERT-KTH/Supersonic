#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
typedef pair<int, int> Pr;
int N, H;
int d[99999], h[99999]; // Reduce size of d by 1
const int size = 1 << 20;
int seg_v[size * 2 - 1];
int seg_a[size * 2 - 1];
Pr rmq[size * 2 - 1];

// ... code omitted for brevity ...

void solve() {
  long long int res = 0;
  for (int i = 0; i < N; i++) {
    rmq_update(i, h[i]);
  }
  seg_add(0, N, H);
  for (int fl = 0; fl < N; fl++) {
    int seg_max_fl = seg_getMax(fl, fl + 1); // store value in variable
    if (seg_max_fl > H) {
      seg_add(fl, N, H - seg_max_fl);
    }
    seg_add(fl, N, -d[fl]);
    if (seg_max_fl > 0)
      continue;
    while (true) {
      int idx = rmq_getMaxIdx(0, fl);
      int seg_max_idx_fl = seg_getMax(idx, fl); // store value in variable
      if (h[idx] > H - seg_max_idx_fl) {
        h[idx] = H - seg_max_idx_fl;
        rmq_update(idx, h[idx]);
        continue;
      }
      int s = (H - seg_max_idx_fl) / h[idx];
      int hp = seg_max_fl; // use stored value
      int need = -hp + 1;
      int t = (need / h[idx]) + !!(need % h[idx]);
      int num = min(s, t);
      seg_add(idx, N, h[idx] * num);
      res += num;
      if (seg_max_fl > 0)
        break;
    }
  }
  printf("%lld\n", res);
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL); // speed up I/O operations
  scanf("%d %d", &N, &H);
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", d + i + 1, h + i);
  }
  solve();
}
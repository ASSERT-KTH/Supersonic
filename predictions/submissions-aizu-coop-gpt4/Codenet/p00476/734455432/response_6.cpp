#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
typedef pair<int, int> Pr;
int N, H;
int d[100000], h[100000];
const int size = 1 << 20;
int seg_v[size * 2 - 1];
int seg_a[size * 2 - 1];
Pr rmq[size * 2 - 1];

// Rest of the code remains the same

void solve() {
  long long int res = 0;
  for (int i = 0; i < N; i++) {
    rmq_update(i, h[i]);
  }
  seg_add(0, N, H);
  for (int fl = 0; fl < N; fl++) {
    int segMax = seg_getMax(fl, fl + 1); // Store result of function call
    if (segMax > H) {
      seg_add(fl, N, H - segMax);
    }
    seg_add(fl, N, -d[fl]);
    segMax = seg_getMax(fl, fl + 1); // Reuse stored result
    if (segMax > 0)
      continue;
    while (true) {
      int idx = rmq_getMaxIdx(0, fl);
      if (h[idx] > H - seg_getMax(idx, fl)) {
        h[idx] = H - seg_getMax(idx, fl);
        rmq_update(idx, h[idx]);
        continue;
      }
      int s = (H - seg_getMax(idx, fl)) / h[idx];
      int hp = segMax; // Reuse stored result
      int need = -hp + 1;
      int t = (need / h[idx]) + !!(need % h[idx]);
      int num = min(s, t);
      seg_add(idx, N, h[idx] * num);
      res += num;
      if (seg_getMax(fl, fl + 1) > 0)
        break;
    }
  }
  printf("%lld\n", res);
}

// Rest of the code remains the same
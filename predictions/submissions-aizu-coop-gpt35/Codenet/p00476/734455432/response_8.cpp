#include <bits/stdc++.h>
using namespace std;
const int INF = 1 << 28;
typedef pair<int, int> Pr;

void seg_add(int l, int r, int x, int k = 0, int a = 0, int b = size);
int seg_getMax(int l, int r, int k = 0, int a = 0, int b = size);
void rmq_update(int k, int x);
Pr _rmq_getMax(int l, int r, int k = 0, int a = 0, int b = size);

void solve() {
  long long int res = 0;
  for (int i = 0; i < N; i++) {
    rmq_update(i, h[i]);
  }
  seg_add(0, N, H);
  for (int fl = 0; fl < N; fl += 2) {
    if (seg_getMax(fl, fl + 1) > H) {
      seg_add(fl, N, H - seg_getMax(fl, fl + 1));
    }
    seg_add(fl, N, -d[fl]);
    if (seg_getMax(fl, fl + 1) > 0)
      continue;
    while (true) {
      int idx = rmq_getMaxIdx(0, fl);
      if (h[idx] > H - seg_getMax(idx, fl)) {
        h[idx] = H - seg_getMax(idx, fl);
        rmq_update(idx, h[idx]);
        continue;
      }
      int s = (H - seg_getMax(idx, fl)) / h[idx];
      int hp = seg_getMax(fl, fl + 1);
      int need = -hp + 1;
      int t = (need / h[idx]) + !!(need % h[idx]);
      int num = min(s, t);
      seg_add(idx, N, h[idx] * num);
      res += num;
      if (seg_getMax(fl, fl + 1) > 0)
        break;
    }

    // Process the second element in the pair
    int fl2 = fl + 1;
    if (fl2 < N) {
      if (seg_getMax(fl2, fl2 + 1) > H) {
        seg_add(fl2, N, H - seg_getMax(fl2, fl2 + 1));
      }
      seg_add(fl2, N, -d[fl2]);
      if (seg_getMax(fl2, fl2 + 1) > 0)
        continue;
      while (true) {
        int idx = rmq_getMaxIdx(0, fl2);
        if (h[idx] > H - seg_getMax(idx, fl2)) {
          h[idx] = H - seg_getMax(idx, fl2);
          rmq_update(idx, h[idx]);
          continue;
        }
        int s = (H - seg_getMax(idx, fl2)) / h[idx];
        int hp = seg_getMax(fl2, fl2 + 1);
        int need = -hp + 1;
        int t = (need / h[idx]) + !!(need % h[idx]);
        int num = min(s, t);
        seg_add(idx, N, h[idx] * num);
        res += num;
        if (seg_getMax(fl2, fl2 + 1) > 0)
          break;
      }
    }
  }
  printf("%lld\n", res);
}

int main() {
  scanf("%d %d", &N, &H);
  vector<int> d(N), h(N);
  for (int i = 0; i < N - 1; i++) {
    scanf("%d %d", &d[i + 1], &h[i]);
  }
  solve();
}
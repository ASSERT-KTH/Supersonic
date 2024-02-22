#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <utility>
typedef long long ll;
typedef std::pair<int, int> P;
const static int tx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const static int ty[] = {-1, -1, 0, 1, 1, 1, 0, -1};
static const double EPS = 1e-8;

int main() {
  int num_of_notes;
  int num_of_beauty;
  ll force_of_repulsion;
  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty,
                &force_of_repulsion)) {
    int notes[2001];
    ll beauty[100001];
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", notes + note_idx);
      notes[note_idx]--;
    }
    ll sum[200001];
    memset(sum, 0, sizeof(sum));
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%lld", beauty + beauty_idx);
      sum[beauty_idx] =
          (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }
    std::sort(notes, notes + num_of_notes);
    ll res = LINF;
    ll lhs = sum[notes[0]];
    ll rhs = 0;
    for (int i = num_of_notes - 1; i >= 0; i--) {
      int next = i + 1;
      for (int j = 0; j <= i; j++) {
        ll val = (lhs - rhs) / force_of_repulsion;
        res = std::min(res, dp[j] + val);
        dp[j] = std::min(dp[j], dp[i] + val);
      }
      lhs = (notes[i] - 1 < 0 ? 0 : sum[notes[i] - 1]);
      rhs = sum[notes[i]];
    }
    res = std::min(dp[0] + (lhs - rhs) / force_of_repulsion, res);
    printf("%lld\n", res);
  }
}
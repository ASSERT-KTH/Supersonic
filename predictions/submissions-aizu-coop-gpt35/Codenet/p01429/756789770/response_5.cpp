#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#include <cstdio>
#include <cstring>
#include <iostream>

typedef long long ll;
typedef std::pair<int, int> P;
typedef std::pair<int, P> PP;
const static int tx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const static int ty[] = {-1, -1, 0, 1, 1, 1, 0, -1};
static const double EPS = 1e-8;

ll compute(ll* sum, int* notes, ll force_of_repulsion, int i, int j) {
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}

int main() {
  int num_of_notes;
  int num_of_beauty;
  ll force_of_repulsion;

  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty,
                &force_of_repulsion)) {
    int notes[2001];
    ll beauty[100001];
    ll sum[200001];

    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", notes + note_idx);
      notes[note_idx]--;
    }

    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%lld", beauty + beauty_idx);
      sum[beauty_idx] =
          (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }

    ll dp[2001];
    std::fill(dp, dp + 2001, LINF);
    dp[0] = 0;

    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      for (int j = 0; j <= i; j++) {
        dp[next] = std::min(dp[next], dp[i] + compute(sum, notes, force_of_repulsion, i, next));
        dp[next] = std::min(dp[next], dp[i] + compute(sum, notes, force_of_repulsion, j, next));
      }
    }

    ll res = LINF;
    for (int i = 0; i < num_of_notes; i++) {
      res = std::min(dp[num_of_notes - 1] + compute(sum, notes, force_of_repulsion, i, num_of_notes - 1), res);
    }

    printf("%lld\n", res);
  }
}
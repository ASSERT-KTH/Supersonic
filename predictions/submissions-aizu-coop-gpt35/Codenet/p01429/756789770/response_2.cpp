#include <algorithm>
#include <cstdio>

const static int tx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const static int ty[] = {-1, -1, 0, 1, 1, 1, 0, -1};
static const double EPS = 1e-8;

typedef long long ll;
typedef std::pair<int, int> P;
typedef std::pair<int, P> PP;

ll compute(const ll* sum, const int* notes, ll force_of_repulsion, int i, int j) {
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}

int main() {
  int num_of_notes;
  int num_of_beauty;
  ll force_of_repulsion;

  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty, &force_of_repulsion)) {
    int notes[2001];
    ll sum[200001];
    ll beauty[100001];

    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", notes + note_idx);
      notes[note_idx]--;
    }

    std::fill(sum, sum + num_of_beauty, 0);
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%lld", beauty + beauty_idx);
      sum[beauty_idx] = (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }

    std::partial_sort(notes, notes + num_of_notes, notes + num_of_beauty, std::greater<int>());

    ll dp[2001][2001];
    std::fill(&dp[0][0], &dp[0][0] + sizeof(dp) / sizeof(dp[0][0]), LLONG_MAX);
    dp[0][0] = 0;

    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      ll compute_i_next = compute(sum, notes, force_of_repulsion, i, next);
      for (int j = 0; j <= i; j++) {
        ll compute_j_next = compute(sum, notes, force_of_repulsion, j, next);
        dp[next][j] = std::min(dp[next][j], dp[i][j] + compute_i_next);
        dp[next][i] = std::min(dp[next][i], dp[i][j] + compute_j_next);
      }
    }

    ll res = LLONG_MAX;
    for (int i = 0; i < num_of_notes; i++) {
      ll compute_i_num_of_notes = compute(sum, notes, force_of_repulsion, i, num_of_notes - 1);
      res = std::min(dp[num_of_notes - 1][i] + compute_i_num_of_notes, res);
    }

    printf("%lld\n", res);
  }
}
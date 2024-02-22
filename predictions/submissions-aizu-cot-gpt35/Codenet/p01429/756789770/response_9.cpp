#include <algorithm>
#include <cstdio>
#include <cstring>

typedef long long ll;

const static int tx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const static int ty[] = {-1, -1, 0, 1, 1, 1, 0, -1};
static const double EPS = 1e-8;

int num_of_notes;
int num_of_beauty;
ll force_of_repulsion;

ll sum[200001];
ll dp[2001][2001];
int notes[2001];
ll beauty[100001];

ll compute(int i, int j) {
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}

int main() {
  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty,
                &force_of_repulsion)) {
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", notes + note_idx);
      notes[note_idx]--;
    }

    memset(sum, 0, sizeof(sum));
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%d", beauty + beauty_idx);
      sum[beauty_idx] =
          (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }

    std::sort(notes, notes + num_of_notes);

    ll prefix_sum = 0;
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      prefix_sum += beauty[beauty_idx];
      sum[beauty_idx] = prefix_sum;
    }

    int left = 0, right = num_of_notes - 1;
    while (left < right) {
      std::swap(notes[left], notes[right]);
      left++;
      right--;
    }

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      ll compute_i_next = compute(i, next);
      ll compute_j_next = compute(next, next);
      for (int j = 0; j <= i; j++) {
        dp[next][j] = std::min(dp[next][j], dp[i][j] + compute_i_next);
        dp[next][i] = std::min(dp[next][i], dp[i][j] + compute_j_next);
      }
    }

    ll res = dp[num_of_notes - 1][0] + compute(0, num_of_notes - 1);
    for (int i = 1; i < num_of_notes; i++) {
      res = std::min(dp[num_of_notes - 1][i] + compute(i, num_of_notes - 1), res);
    }

    printf("%lld\n", res);
  }
}
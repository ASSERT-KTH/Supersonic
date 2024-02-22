#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

typedef long long ll;

const static int tx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const static int ty[] = {-1, -1, 0, 1, 1, 1, 0, -1};
static const double EPS = 1e-8;

int num_of_notes;
int num_of_beauty;
ll force_of_repulsion;

std::vector<ll> sum;
std::vector<int> notes;
std::vector<ll> beauty;

double compute(int i, int j) {
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / static_cast<double>(force_of_repulsion);
}

int main() {
  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty,
                &force_of_repulsion)) {
    notes.resize(num_of_notes);
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", &notes[note_idx]);
      notes[note_idx]--;
    }

    sum.resize(num_of_beauty);
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%lld", &beauty[beauty_idx]);
      sum[beauty_idx] = (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }

    std::sort(notes.begin(), notes.end());

    std::vector<ll> dp(num_of_notes, 1e18);
    dp[0] = 0;

    for (int i = 0; i < num_of_notes; i++) {
      for (int j = 0; j <= i; j++) {
        dp[i + 1] = std::min(dp[i + 1], dp[i] + compute(i, i + 1));
        dp[i + 1] = std::min(dp[i + 1], dp[i] + compute(j, i + 1));
      }
    }

    ll res = 1e18;
    for (int i = 0; i < num_of_notes; i++) {
      res = std::min(dp[num_of_notes - 1] + compute(i, num_of_notes - 1), res);
    }
    printf("%lld\n", res);
  }
}
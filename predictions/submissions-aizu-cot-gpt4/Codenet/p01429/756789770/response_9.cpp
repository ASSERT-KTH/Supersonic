#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
const static ll LINF = 0x3f3f3f3f3f3f3f3f;
ll compute(const VI& notes, const VI& sum, ll force_of_repulsion, int i, int j) {
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}
int main() {
  int num_of_notes, num_of_beauty;
  ll force_of_repulsion;
  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty, &force_of_repulsion)) {
    VI notes(num_of_notes), sum(num_of_beauty), dp(num_of_notes);
    for (int i = 0; i < num_of_notes; ++i) {
      scanf("%d", &notes[i]);
      --notes[i];
    }
    for (int i = 0; i < num_of_beauty; ++i) {
      scanf("%d", &sum[i]);
      sum[i] += (i - 1 >= 0 ? sum[i - 1] : 0);
    }
    sort(notes.begin(), notes.end(), greater<int>());
    fill(dp.begin(), dp.end(), LINF);
    dp[0] = 0;
    for (int i = 0; i < num_of_notes; ++i) {
      for (int j = 0; j <= i; ++j) {
        dp[i + 1] = min({dp[i + 1], dp[i] + compute(notes, sum, force_of_repulsion, i, i + 1), dp[i] + compute(notes, sum, force_of_repulsion, j, i + 1)});
      }
    }
    ll res = LINF;
    for (int i = 0; i < num_of_notes; ++i) {
      res = min(res, dp[num_of_notes - 1] + compute(notes, sum, force_of_repulsion, i, num_of_notes - 1));
    }
    printf("%lld\n", res);
  }
}
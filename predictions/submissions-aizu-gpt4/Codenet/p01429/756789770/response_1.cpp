#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
typedef long long ll;
const static int tx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const static int ty[] = {-1, -1, 0, 1, 1, 1, 0, -1};
static const double EPS = 1e-8;
int num_of_notes;
int num_of_beauty;
ll force_of_repulsion;
vector<ll> sum;
vector<vector<ll>> dp;
vector<int> notes;
vector<ll> beauty;

ll compute(int i, int j) {
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}

int main() {
  while (scanf("%d %d %lld", &num_of_notes, &num_of_beauty, &force_of_repulsion) == 3) {
    notes.resize(num_of_notes);
    sum.assign(num_of_beauty, 0);
    beauty.resize(num_of_beauty);
    dp.assign(num_of_notes, vector<ll>(num_of_notes, 0x3f3f3f3f3f3f3f3f));
    for (int note_idx = 0; note_idx < num_of_notes; ++note_idx) {
      scanf("%d", &notes[note_idx]);
      --notes[note_idx];
    }
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; ++beauty_idx) {
      scanf("%d", &beauty[beauty_idx]);
      sum[beauty_idx] = (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }
    sort(notes.begin(), notes.end(), greater<int>());
    dp[0][0] = 0;
    for (int i = 0; i < num_of_notes; ++i) {
      int next = i + 1;
      for (int j = 0; j <= i; ++j) {
        dp[next][j] = min(dp[next][j], dp[i][j] + compute(i, next));
        dp[next][i] = min(dp[next][i], dp[i][j] + compute(j, next));
      }
    }
    ll res = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < num_of_notes; ++i) {
      res = min(dp[num_of_notes - 1][i] + compute(i, num_of_notes - 1), res);
    }
    printf("%lld\n", res);
  }
}
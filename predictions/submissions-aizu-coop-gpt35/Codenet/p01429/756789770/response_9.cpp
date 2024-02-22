#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#include <cstdio>
#include <vector>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, P> PP;
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
  ll lhs = sum[notes[i]] - (notes[j] - 1 >= 0 ? sum[notes[j] - 1] : 0);
  return lhs / force_of_repulsion;
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
      sum[beauty_idx] =
          (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }
    dp.resize(num_of_notes + 1, vector<ll>(num_of_notes + 1, LINF));
    dp[0][0] = 0;
    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      ll compute_i_next = compute(i, next);
      for (int j = 0; j < i; j++) {
        dp[next][j] = min(dp[next][j], dp[i][j] + compute_i_next);
        dp[next][i] = min(dp[next][i], dp[i][j] + compute(j, next));
      }
      dp[next][i] = min(dp[next][i], dp[i][i] + compute_i_next);
    }
    ll res = LINF;
    for (int i = 0; i < num_of_notes; i++) {
      res = min(dp[num_of_notes][i] + compute(i, num_of_notes), res);
    }
    printf("%lld\n", res);
  }
}
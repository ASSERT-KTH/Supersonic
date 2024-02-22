#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#include <algorithm>
#include <cmath>
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
vector<ll> sum(200001);
vector<vector<ll>> dp(2001, vector<ll>(2001, INF));
vector<int> notes(2001);
vector<ll> beauty(100001);
ll compute(int i, int j) {
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}
int main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty,
                &force_of_repulsion)) {
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", &notes[note_idx]);
      notes[note_idx]--;
    }
    sum[0] = 0;
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%d", &beauty[beauty_idx]);
      sum[beauty_idx] =
          (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }
    sort(notes.begin(), notes.begin() + num_of_notes);
    reverse(notes.begin(), notes.begin() + num_of_notes);
    dp[0][0] = 0;
    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      for (int j = 0; j <= i; j++) {
        ll comp = compute(i, next);
        dp[next][j] = min(dp[next][j], dp[i][j] + comp);
        dp[next][i] = min(dp[next][i], dp[i][j] + comp);
      }
    }
    ll res = LINF;
    for (int i = 0; i < num_of_notes; i++) {
      res = min(dp[num_of_notes - 1][i] + compute(i, num_of_notes - 1), res);
    }
    printf("%lld\n", res);
  }
}
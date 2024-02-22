#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

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
ll compute(int i, int j, const ll* sum, const int* notes, ll force_of_repulsion) {
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}

int main() {
  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty, &force_of_repulsion)) {
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", notes + note_idx);
      notes[note_idx]--;
    }

    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%lld", beauty + beauty_idx);
    }

    sum[0] = beauty[0];
    for (int beauty_idx = 1; beauty_idx < num_of_beauty; beauty_idx++) {
      sum[beauty_idx] = sum[beauty_idx - 1] + beauty[beauty_idx];
    }

    sort(notes, notes + num_of_notes, greater<int>());
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    int next;
    for (int i = 0; i < num_of_notes; i++) {
      next = i + 1;
      for (int j = 0; j <= i; j++) {
        dp[next][j] = min(dp[next][j], dp[i][j] + compute(i, next, sum, notes, force_of_repulsion));
        dp[next][i] = min(dp[next][i], dp[i][j] + compute(j, next, sum, notes, force_of_repulsion));
      }
    }

    ll res = dp[num_of_notes - 1][0] + compute(0, num_of_notes - 1, sum, notes, force_of_repulsion);
    for (int i = 1; i < num_of_notes; i++) {
      res = min(dp[num_of_notes - 1][i] + compute(i, num_of_notes - 1, sum, notes, force_of_repulsion), res);
    }

    printf("%lld\n", res);
  }
}
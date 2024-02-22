#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

const static int tx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const static int ty[] = {-1, -1, 0, 1, 1, 1, 0, -1};
static const double EPS = 1e-8;

int num_of_notes;
int num_of_beauty;
long long force_of_repulsion;
long long sum[200001];
long long dp[2001][2001];
int notes[2001];
long long beauty[100001];

long long compute(int i, int j) {
  long long lhs = sum[notes[i]];
  long long rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}

int main() {
  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty, &force_of_repulsion)) {
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", notes + note_idx);
      notes[note_idx]--;
    }

    memset(sum, 0, sizeof(sum));
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%lld", beauty + beauty_idx);
      sum[beauty_idx] = (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }

    sort(notes, notes + num_of_notes, greater<int>());

    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;

    for (int i = 0; i < num_of_notes; i++) {
      for (int j = 0; j <= i; j++) {
        dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + compute(i, i + 1));
        dp[i + 1][i] = min(dp[i + 1][i], dp[i][j] + compute(j, i + 1));
      }
    }

    long long res = LINF;
    for (int i = 0; i < num_of_notes; i++) {
      res = min(dp[num_of_notes][i] + compute(i, num_of_notes - 1), res);
    }

    printf("%lld\n", res);
  }
}
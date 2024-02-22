#include <algorithm>
#include <cstdio>
#include <cstring>

const static int tx[] = {0, 1, 1, 1, 0, -1, -1, -1};
const static int ty[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const static double EPS = 1e-8;
const static int MAX_NOTES = 2001;
const static int MAX_BEAUTY = 100001;
const static long long INF = 0x3f3f3f3f3f3f3f3f;

int num_of_notes;
int num_of_beauty;
long long force_of_repulsion;
long long sum[MAX_BEAUTY];
long long dp[MAX_NOTES][MAX_NOTES];
int notes[MAX_NOTES];
long long beauty[MAX_BEAUTY];

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
      sum[beauty_idx] = (beauty_idx > 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }
    std::sort(notes, notes + num_of_notes, std::greater<int>());
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      for (int j = 0; j <= i; j++) {
        dp[next][j] = std::min(dp[next][j], dp[i][j] + compute(i, next));
        dp[next][i] = std::min(dp[next][i], dp[i][j] + compute(j, next));
      }
    }
    long long res = INF;
    for (int i = 0; i < num_of_notes; i++) {
      res = std::min(dp[num_of_notes - 1][i] + compute(i, num_of_notes - 1), res);
    }
    printf("%lld\n", res);
  }
}
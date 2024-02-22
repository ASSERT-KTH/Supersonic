#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;

int num_of_notes;
int num_of_beauty;
int force_of_repulsion;
int notes[2001];
int beauty[100001];
int sum[100001];
int dp[2001][2001];

int main() {
  while (~scanf("%d %d %d", &num_of_notes, &num_of_beauty, &force_of_repulsion)) {
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", notes + note_idx);
      notes[note_idx]--;
    }
    memset(sum, 0, sizeof(sum));
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%d", beauty + beauty_idx);
      sum[beauty_idx] = (beauty_idx > 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }
    sort(notes, notes + num_of_notes);
    reverse(notes, notes + num_of_notes);
    memset(dp, INF, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      for (int j = 0; j <= i; j++) {
        dp[next][j] = min(dp[next][j], dp[i][j] + (sum[notes[i]] - (notes[j] - 1 >= 0 ? sum[notes[j] - 1] : 0)) / force_of_repulsion);
        dp[next][i] = min(dp[next][i], dp[i][j] + (sum[notes[i]] - (notes[j] - 1 >= 0 ? sum[notes[j] - 1] : 0)) / force_of_repulsion);
      }
    }
    int res = INF;
    for (int i = 0; i < num_of_notes; i++) {
      res = min(dp[num_of_notes - 1][i] + (sum[notes[i]] - (notes[num_of_notes - 1] - 1 >= 0 ? sum[notes[num_of_notes - 1] - 1] : 0)) / force_of_repulsion, res);
    }
    printf("%d\n", res);
  }
}
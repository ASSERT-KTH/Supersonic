#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;
typedef pair<int, int> P;

int num_of_notes;
int num_of_beauty;
ll force_of_repulsion;
ll sum[200001];
ll dp[2001][2001];
int notes[2001];
ll beauty[100001];

ll compute(int i, int j, ll lhs, ll rhs) {
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
      scanf("%lld", beauty + beauty_idx);
      sum[beauty_idx] =
          (beauty_idx > 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }
    sort(notes, notes + num_of_notes);
    reverse(notes, notes + num_of_notes);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      ll lhs = sum[notes[i]];
      ll rhs = (notes[next] - 1 < 0 ? 0 : sum[notes[next] - 1]);
      for (int j = 0; j <= i; j++) {
        dp[next][j] = min(dp[next][j], dp[i][j] + compute(i, next, lhs, rhs));
        dp[next][i] = min(dp[next][i], dp[i][j] + compute(j, next, lhs, rhs));
      }
    }
    ll res = LINF;
    for (int i = 0; i < num_of_notes; i++) {
      ll lhs = sum[notes[num_of_notes - 1]];
      ll rhs = (notes[i] - 1 < 0 ? 0 : sum[notes[i] - 1]);
      res = min(dp[num_of_notes - 1][i] + compute(i, num_of_notes - 1, lhs, rhs), res);
    }
    printf("%lld\n", res);
  }
}
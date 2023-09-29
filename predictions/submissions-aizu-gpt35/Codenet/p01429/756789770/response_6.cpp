#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static int MAXN = 2005;
const static int MAXM = 100005;
const static ll LINF = 0x3f3f3f3f3f3f3f3f;
int num_of_notes;
int num_of_beauty;
ll force_of_repulsion;
ll sum[MAXM];
ll dp[MAXN][MAXN];
int notes[MAXN];
ll beauty[MAXM];
ll compute(int i, int j) {
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  while (cin >> num_of_notes >> num_of_beauty >> force_of_repulsion) {
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      cin >> notes[note_idx];
      notes[note_idx]--;
    }
    memset(sum, 0, sizeof(sum));
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      cin >> beauty[beauty_idx];
      sum[beauty_idx] = (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) +
                        beauty[beauty_idx];
    }
    sort(notes, notes + num_of_notes);
    reverse(notes, notes + num_of_notes);
    memset(dp, 0x3f, sizeof(dp));
    dp[0][0] = 0;
    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      for (int j = 0; j <= i; j++) {
        dp[next][j] = min(dp[next][j], dp[i][j] + compute(i, next));
        dp[next][i] = min(dp[next][i], dp[i][j] + compute(j, next));
      }
    }
    ll res = LINF;
    for (int i = 0; i < num_of_notes; i++) {
      res = min(dp[num_of_notes - 1][i] + compute(i, num_of_notes - 1), res);
    }
    cout << res << "\n";
  }
  return 0;
}
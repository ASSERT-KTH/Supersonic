#include <bits/stdc++.h>
using namespace std;

const int N = 2005;
const int M = 1e5 + 5;

int num_of_notes;
int num_of_beauty;
long long force_of_repulsion;
long long sum[M];
long long dp[N][N];
int notes[N];
long long beauty[M];

long long compute(int i, int j) {
  long long lhs = sum[notes[i]];
  long long rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

  while (cin >> num_of_notes >> num_of_beauty >> force_of_repulsion) {
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      cin >> notes[note_idx];
      notes[note_idx]--;
    }

    sum[0] = beauty[0] = 0;
    for (int beauty_idx = 1; beauty_idx <= num_of_beauty; beauty_idx++) {
      cin >> beauty[beauty_idx];
      sum[beauty_idx] = sum[beauty_idx - 1] + beauty[beauty_idx];
    }

    sort(notes, notes + num_of_notes);
    reverse(notes, notes + num_of_notes);

    for (int i = 0; i <= num_of_notes; i++) {
      for (int j = 0; j <= num_of_notes; j++) {
        dp[i][j] = 1e18;
      }
    }
    dp[0][0] = 0;

    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      for (int j = 0; j <= i; j++) {
        dp[next][j] = min(dp[next][j], dp[i][j] + compute(i, next));
        dp[next][i] = min(dp[next][i], dp[i][j] + compute(j, next));
      }
    }

    long long res = 1e18;
    for (int i = 0; i < num_of_notes; i++) {
      res = min(dp[num_of_notes][i] + compute(i, num_of_notes), res);
    }

    cout << res << endl;
  }
  return 0;
}
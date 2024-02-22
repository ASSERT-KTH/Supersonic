#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <numeric>
#include <utility>
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
ll sum[200001];
ll dp[2001][2001];
int notes[2001];
ll beauty[100001];
ll computed[2001][2001];
ll compute(int i, int j) {
  return computed[i][j];
}
int main() {
  while (cin >> num_of_notes >> num_of_beauty >> force_of_repulsion) {
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      cin >> notes[note_idx];
      notes[note_idx]--;
    }
    memset(sum, 0, sizeof(sum));
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      cin >> beauty[beauty_idx];
    }
    partial_sum(beauty, beauty + num_of_beauty, sum);
    sort(notes, notes + num_of_notes);
    reverse(notes, notes + num_of_notes);
    memset(dp, 0x3f, sizeof(dp));
    memset(computed, 0, sizeof(computed));
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
    cout << res << endl;
  }
}
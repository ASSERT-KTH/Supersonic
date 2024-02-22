#define _USE_MATH_DEFINES
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f3f
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
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
vector<vector<ll>> dp(2001, vector<ll>(2001));
vector<int> notes(2001);
vector<ll> beauty(100001);
map<pair<int, int>, ll> memo; // Added memoization map
ll compute(int i, int j) {
  // Check if this combination is already calculated
  if (memo.count(make_pair(i, j))) {
    return memo[make_pair(i, j)];
  }
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  // Save the result in memo
  memo[make_pair(i, j)] = (lhs - rhs) / force_of_repulsion;
  return memo[make_pair(i, j)];
}
int main() {
  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty,
                &force_of_repulsion)) {
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", &notes[note_idx]);
      notes[note_idx]--;
    }
    fill(sum.begin(), sum.end(), 0);
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%d", &beauty[beauty_idx]);
      sum[beauty_idx] =
          (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }
    sort(notes.begin(), notes.begin() + num_of_notes);
    reverse(notes.begin(), notes.begin() + num_of_notes);
    for (auto &v : dp) {
      fill(v.begin(), v.end(), INF);
    }
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
    printf("%lld\n", res);
  }
}
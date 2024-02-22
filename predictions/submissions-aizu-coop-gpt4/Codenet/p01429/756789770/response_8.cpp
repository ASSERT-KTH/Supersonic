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
ll compute_cache[2001][2001]; // cache for compute function results
bool compute_cached[2001][2001]; // flags to indicate whether a result is in the cache
ll compute(int i, int j) {
  if (!compute_cached[i][j]) { // if the result is not in the cache
    ll lhs = sum[notes[i]];
    ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
    compute_cache[i][j] = (lhs - rhs) / force_of_repulsion; // compute and store the result in the cache
    compute_cached[i][j] = true; // set the flag to indicate that the result is in the cache
  }
  return compute_cache[i][j]; // return the result from the cache
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
      scanf("%d", beauty + beauty_idx);
      sum[beauty_idx] =
          (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }
    sort(notes, notes + num_of_notes, greater<int>()); // sort in descending order
    memset(dp, 0x3f, sizeof(dp));
    memset(compute_cache, 0, sizeof(compute_cache)); // initialize the cache
    memset(compute_cached, false, sizeof(compute_cached)); // initialize the flags
    dp[0][0] = 0;
    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      for (int j = 0; j <= i; j++) {
        ll new_dp_next_j = dp[i][j] + compute(i, next);
        ll new_dp_next_i = dp[i][j] + compute(j, next);
        if (dp[next][j] <= new_dp_next_j && dp[next][i] <= new_dp_next_i)
          break; // if dp[next][j] and dp[next][i] are not modified, break the loop
        dp[next][j] = min(dp[next][j], new_dp_next_j);
        dp[next][i] = min(dp[next][i], new_dp_next_i);
      }
    }
    ll res = LINF;
    for (int i = 0; i < num_of_notes; i++) {
      res = min(dp[num_of_notes - 1][i] + compute(i, num_of_notes - 1), res);
    }
    printf("%lld\n", res);
  }
}
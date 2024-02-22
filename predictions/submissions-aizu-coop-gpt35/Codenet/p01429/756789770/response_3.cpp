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
vector<int> notes;
vector<ll> beauty;
vector<ll> sum;

ll compute(int i, int j) {
  ll lhs = sum[notes[i]];
  ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
  return (lhs - rhs) / force_of_repulsion;
}

int main() {
  while (~scanf("%d %d %lld", &num_of_notes, &num_of_beauty,
                &force_of_repulsion)) {
    notes.resize(num_of_notes);
    for (int note_idx = 0; note_idx < num_of_notes; note_idx++) {
      scanf("%d", &notes[note_idx]);
      notes[note_idx]--;
    }
    
    sum.resize(num_of_beauty);
    for (int beauty_idx = 0; beauty_idx < num_of_beauty; beauty_idx++) {
      scanf("%lld", &beauty[beauty_idx]);
      sum[beauty_idx] = (beauty_idx - 1 >= 0 ? sum[beauty_idx - 1] : 0) + beauty[beauty_idx];
    }
    
    sort(notes.begin(), notes.end(), greater<int>());
    
    vector<vector<ll>> dp(num_of_notes + 1, vector<ll>(num_of_notes + 1, LINF));
    dp[0][0] = 0;
    
    for (int i = 0; i < num_of_notes; i++) {
      int next = i + 1;
      ll lhs = sum[notes[i]];
      for (int j = 0; j <= i; j++) {
        ll rhs = (notes[j] - 1 < 0 ? 0 : sum[notes[j] - 1]);
        dp[next][j] = min(dp[next][j], dp[i][j] + (lhs - rhs) / force_of_repulsion);
        dp[next][i] = min(dp[next][i], dp[i][j] + (lhs - rhs) / force_of_repulsion);
      }
    }
    
    ll res = LINF;
    for (int i = 0; i < num_of_notes; i++) {
      ll lhs = sum[notes[num_of_notes - 1]];
      ll rhs = (notes[i] - 1 < 0 ? 0 : sum[notes[i] - 1]);
      res = min(dp[num_of_notes][i] + (lhs - rhs) / force_of_repulsion, res);
    }
    
    printf("%lld\n", res);
  }
}
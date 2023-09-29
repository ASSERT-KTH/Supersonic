#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

int main() {
  int n;
  scanf("%d", &n);
  int N[n];
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  int t;
  scanf("%d", &t);
  while (t--) {
    int p;
    scanf("%d", &p);
    bool dp[p + 1] = {true};
    for (int i = 1; i <= p; i++) {
      dp[i] = false;
    }
    for (int i = 0; i < n; i++) {
      for (int j = p; j >= N[i]; j--) {
        dp[j] |= dp[j - N[i]];
      }
    }
    if (dp[p]) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
  return 0;
}
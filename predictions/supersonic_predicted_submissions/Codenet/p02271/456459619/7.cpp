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
int *N;
int n;
bool solve(int i, int m) {
  if (i == n) {
    return m == 0 ? true : false;
  }
  return solve(i + 1, m - N[i]) || solve(i + 1, m);
}
int main() {
  int t;
  scanf("%d", &n);
  N = (int *)calloc(n, sizeof(int));
  for (int i = 0; i < n; i++) {
    scanf("%d", &N[i]);
  }
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int p;
    scanf("%d", &p);
    if (solve(0, p)) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
}

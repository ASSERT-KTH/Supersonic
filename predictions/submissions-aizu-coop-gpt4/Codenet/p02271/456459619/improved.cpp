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
bool can_make(int m, int i, int p) {
  if (i == n) {
    return (m == p) ? true : false;
  }
  return can_make(m + N[i], i + 1, p) || can_make(m, i + 1, p);
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
    if (can_make(0, 0, p)) {
      cout << "yes" << endl;
    } else {
      cout << "no" << endl;
    }
  }
}

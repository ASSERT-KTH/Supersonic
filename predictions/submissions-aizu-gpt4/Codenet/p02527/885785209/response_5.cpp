#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
int a[1000010];
template <typename T> void quicksort(T *l, T *r) {
  T *begin = l;
  struct range {
    T *l, *r;
  };
  static range s[300];
  auto partition = [&](T *l, T *r) {
    T *piv = l + (r-l)/2;
    T pivotValue = *piv;
    swap(*piv, *(r - 1));
    piv = l;
    for (T* i = l; i < r; i++) {
        if (*i < pivotValue) {
            swap(*i, *piv);
            piv++;
        }
    }
    swap(*piv, *(r - 1));
    return piv;
  };
  int sz = 0;
  s[sz++] = {l, r};
  while (sz) {
    T *l = s[--sz].l;
    T *r = s[sz].r;
    T *p = partition(l, r);
    if (p != nullptr) {
      if (p + 1 < r)
        s[sz++] = {p + 1, r};
      if (l < p)
        s[sz++] = {l, p};
    }
  }
}
int main() {
  srand(time(0));
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
  quicksort(a, a + n);
  for (int i = 0; i < n; i++)
    printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
}
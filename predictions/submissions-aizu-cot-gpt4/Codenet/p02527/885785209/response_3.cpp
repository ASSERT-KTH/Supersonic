#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;
int a[1000010];
template <typename T> void quicksort(T *l, T *r) {
  T *begin = l;
  struct range {
    T *l, *r;
  };
  static range s[300];
  auto partition = [&](T *l, T *r) {
    if (r - l < 2)
      return (T *)nullptr;
    T *piv = l + rand() % (r - l);
    if (*piv == *max_element(l, r)) {
      swap(*piv, *(r - 1));
      return r - 1;
    }
    swap(*l, *piv);
    piv = l;
    r--;
    while (l < r) {
      while (l < r && *l <= *piv)
        l++;
      while (l<r && * r> * piv)
        r--;
      swap(*l, *r);
    }
    T *p = l - 1;
    swap(*p, *piv);
    return p;
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
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", a + i);
  quicksort(a, a + n);
  for (int i = 0; i < n; i++)
    printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
}
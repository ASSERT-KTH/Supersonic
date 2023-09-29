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
  static range s[200];
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
        s
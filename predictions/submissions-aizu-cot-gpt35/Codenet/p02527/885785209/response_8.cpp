#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <random>
using namespace std;

int a[1000010];

template <typename Iter>
void quicksort(Iter l, Iter r) {
  struct range {
    Iter l, r;
  };
  static range s[300];
  auto partition = [&](Iter l, Iter r) {
    if (r - l < 2)
      return Iter(nullptr);
    Iter piv = l + rand() % (r - l);
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
      while (l < r && *r > *piv)
        r--;
      swap(*l, *r);
    }
    Iter p = l - 1;
    swap(*p, *piv);
    return p;
  };
  int sz = 0;
  s[sz++] = {l, r};
  while (sz) {
    Iter l = s[--sz].l;
    Iter r = s[sz].r;
    Iter p = partition(l, r);
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
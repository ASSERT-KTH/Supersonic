#define _CRT_SECURE_NO_WARNINGS
#include <ctime>
#include <iostream>
#include <vector>

int a[1000010];

void quicksort(int *l, int *r) {
  struct range {
    int *l, *r;
  };
  static range s[300];
  auto partition = [&](int *l, int *r) {
    if (r - l < 2)
      return (int *)nullptr;
    int *piv = l + rand() % (r - l);
    if (*piv == *max_element(l, r-1)) {
      swap(*piv, *(r - 1));
      return r - 1;
    }
    swap(*l, *piv);
    piv = l;
    r--;
    while (l < r) {
      while (l < r && *l <= *piv && *(r-1) > *piv)
        l++;
      while (l < r && *r > *piv)
        r--;
      swap(*l, *r);
    }
    int *p = l - 1;
    swap(*p, *piv);
    return p;
  };
  int sz = 0;
  s[sz++] = {l, r};
  while (sz) {
    int *l = s[--sz].l;
    int *r = s[sz].r;
    int *p = partition(l, r);
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
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::cin >> a[i];
  quicksort(a, a + n);
  for (int i = 0; i < n; i++)
    std::cout << a[i] << (i == n - 1 ? '\n' : ' ');
}
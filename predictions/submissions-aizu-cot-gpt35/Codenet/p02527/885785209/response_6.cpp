#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <random>
#include <vector>

int a[1000010];

template <typename T>
void quicksort(T *l, T *r) {
  T *begin = l;
  struct range {
    T *l, *r;
  };
  std::vector<range> s;
  auto partition = [&](T *l, T *r) {
    if (l >= r)
      return (T *)nullptr;
    std::random_device rd;
    std::uniform_int_distribution<int> dist(0, r - l - 1);
    T *piv = l + dist(rd);
    if (*piv == *std::max_element(l, r)) {
      std::swap(*piv, *(r - 1));
      return r - 1;
    }
    std::swap(*l, *piv);
    piv = l;
    r--;
    while (l < r) {
      while (l < r && *l <= *piv)
        l++;
      while (l < r && *r > *piv)
        r--;
      std::swap(*l, *r);
    }
    T *p = l - 1;
    std::swap(*p, *piv);
    return p;
  };
  s.push_back({l, r});
  while (!s.empty()) {
    T *l = s.back().l;
    T *r = s.back().r;
    T *p = partition(l, r);
    s.pop_back();
    if (p != nullptr) {
      if (p + 1 < r)
        s.push_back({p + 1, r});
      if (l < p)
        s.push_back({l, p});
    }
  }
}

int main() {
  std::srand(std::time(0));
  int n;
  std::cin >> n;
  for (int i = 0; i < n; i++)
    std::scanf("%d", a + i);
  quicksort(a, a + n);
  for (int i = 0; i < n; i++)
    std::cout << a[i] << (i == n - 1 ? '\n' : ' ');
  return 0;
}
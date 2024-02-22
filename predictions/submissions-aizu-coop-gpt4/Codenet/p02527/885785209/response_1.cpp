#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cassert>
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
    if (r - l < 2)
      return (T *)nullptr;
    T *piv = l + (r - l) / 2;  // Changed pivot selection
    swap(*l, *piv);
    piv = l;
    r--;
    T *p = r;  // Initialize p to r - 1
    while (l < r) {
      while (l < r && *l <= *piv) {
        l++;
        if (l < r && *l > *piv)  // Update p only when *l > *piv
          p = l - 1;
      }
      while (l < r && *r > *piv)
        r--;
      swap(*l, *r);
    }
    swap(*p, *piv);  // Swap pivot with its final position
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
  cin >> n;  // Replaced scanf with cin
  for (int i = 0; i < n; i++)
    cin >> a[i];  // Replaced scanf with cin
  quicksort(a, a + n);
  for (int i = 0; i < n; i++)
    cout << a[i] << (i == n - 1 ? '\n' : ' ');  // Replaced printf with cout
}
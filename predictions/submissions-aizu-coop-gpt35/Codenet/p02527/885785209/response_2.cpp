#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
using namespace std;

template <typename T>
void quicksort(T *l, T *r) {
  struct range {
    T *l, *r;
  };
  static range s[300];
  int sz = 0;
  s[sz++] = {l, r};
  while (sz) {
    T *l = s[--sz].l;
    T *r = s[sz].r;
    T *p = l + (r - l) / 2;
    T pivot = *p;
    T *i = l, *j = r - 1;
    while (i <= j) {
      while (*i < pivot) i++;
      while (*j > pivot) j--;
      if (i <= j) {
        swap(*i, *j);
        i++;
        j--;
      }
    }
    if (l < j) s[sz++] = {l, j + 1};
    if (i < r) s[sz++] = {i, r};
  }
}

int main() {
  int n;
  cin >> n;
  int *a = new int[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  quicksort(a, a + n);
  for (int i = 0; i < n; i++) {
    cout << a[i] << (i == n - 1 ? '\n' : ' ');
  }
  delete[] a;
  return 0;
}
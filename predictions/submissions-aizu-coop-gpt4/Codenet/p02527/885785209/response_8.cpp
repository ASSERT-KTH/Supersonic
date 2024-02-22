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
  if (r <= l) return;

  T pivot = *(l + rand() % (r - l));
  T *less = l;
  T *greater = r;
  T *i = l;

  while (i < greater) {
    if (*i < pivot) {
      swap(*i, *less);
      i++;
      less++;
    } else if (*i > pivot) {
      greater--;
      swap(*i, *greater);
    } else {
      i++;
    }
  }

  quicksort(l, less);
  quicksort(greater, r);
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
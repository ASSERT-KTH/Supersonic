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
  if (r - l <= 1) 
    return;
  T *piv = l + rand() % (r - l);
  T val = *piv;
  T *i = l, *j = r - 1;
  while (i <= j) {
    while (*i < val) 
      i++;
    while (*j > val) 
      j--;
    if (i <= j)
      swap(*i++, *j--);
  }
  quicksort(l, j + 1);
  quicksort(i, r);
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
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <ctime>
#include <iostream>
#include <vector>
using namespace std;
int a[1000010];

template <typename T> void quicksort(T *l, T *r) {
  if (r - l < 2)
    return;
  T *piv = l + rand() % (r - l);
  T pivot_value = *piv;
  swap(*piv, *(r - 1));
  piv = partition(l, r - 1, [pivot_value](const T &a) { return a < pivot_value; });
  quicksort(l, piv);
  quicksort(piv, r);
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
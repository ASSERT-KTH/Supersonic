#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
int a[1000010];
template <typename T> void quicksort(T *l, T *r) {
  if (r - l < 2)
    return;
  T *piv = l + rand() % (r - l);
  T *p = partition(l, r, [piv](const T& t){ return t < *piv; });
  quicksort(l, p);
  quicksort(p, r);
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
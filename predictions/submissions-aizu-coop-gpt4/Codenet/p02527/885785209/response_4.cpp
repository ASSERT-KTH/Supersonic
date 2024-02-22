#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
int a[1000010];

template <typename T>
void quicksort(T *l, T *r) {
  srand(time(0));
  struct range {
    T *l, *r;
  };
  std::stack<range> s;
  auto partition = [&](T *l, T *r) {
    if (r - l < 2)
      return (T *)nullptr;

    T *piv = l + rand() % (r - l);
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

  s.push({l, r});
  while (!s.empty()) {
    T *l = s.top().l;
    T *r = s.top().r;
    s.pop();
    T *p = partition(l, r);
    if (p != nullptr) {
      if (p + 1 < r)
        s.push({p + 1, r});
      if (l < p)
        s.push({l, p});
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
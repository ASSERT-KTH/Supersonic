#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <random>
using namespace std;

int a[1000010];

template <typename T>
void quicksort(T* l, T* r) {
  T* begin = l;

  auto partition = [&](T* l, T* r) {
    if (r - l < 2)
      return (T*)nullptr;

    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, r - l - 1);
    T* piv = l + dis(gen);

    T max_val = *l;
    for (T* i = l + 1; i < r; i++) {
      if (*i > max_val) {
        max_val = *i;
      }
    }

    if (*piv == max_val) {
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

    T* p = l - 1;
    swap(*p, *piv);
    return p;
  };

  struct range {
    T* l, * r;
  };
  range s[300];
  int sz = 0;
  s[sz++] = { l, r };

  while (sz) {
    T* l = s[--sz].l;
    T* r = s[sz].r;
    T* p = partition(l, r);

    if (p != nullptr) {
      if (p + 1 < r)
        s[sz++] = { p + 1, r };
      if (l < p)
        s[sz++] = { l, p };
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  quicksort(a, a + n);

  for (int i = 0; i < n; i++) {
    cout << a[i] << (i == n - 1 ? '\n' : ' ');
  }

  return 0;
}
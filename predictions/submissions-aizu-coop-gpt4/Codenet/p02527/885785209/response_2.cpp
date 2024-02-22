#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

int a[1000010];
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // Mersenne Twister pseudo-random generator

template <typename T> 
void quicksort(T *l, T *r) {
    struct range {
      T *l, *r;
    };
    static range s[300];
    auto partition = [&](T *l, T *r) {
      if (r - l < 2)
        return (T *)nullptr;
      T *piv = l + rng() % (r - l);
      swap(*(r - 1), *piv);  // Ensure pivot is not the maximum element
      piv = l;
      r--;
      T *j = l;
      for (T *i = l; i < r; i++) {
        if (*i <= *piv) {
            swap(*i, *j);
            j++;
        }
      }
      swap(*j, *piv);
      return j;
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
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
      cin >> a[i];
    quicksort(a, a + n);
    for (int i = 0; i < n; i++)
      cout << a[i] << " ";
    cout << endl;
    return 0;
}
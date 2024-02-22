#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>

void quicksort(int* l, int* r) {
  struct range {
    int* l;
    int* r;
  };
  std::vector<range> s;
  s.push_back({l, r});

  auto partition = [](int* l, int* r) -> int* {
    int* piv = l + std::rand() % (r - l);
    std::swap(*l, *piv);
    piv = l;
    r--;
    int* p = l - 1;
    while (l < r) {
      while (l < r && *l <= *piv)
        l++;
      while (l < r && *r > *piv)
        r--;
      std::swap(*l, *r);
    }
    std::swap(*p, *piv);
    return p;
  };

  while (!s.empty()) {
    int* l = s.back().l;
    int* r = s.back().r;
    s.pop_back();

    int* p = partition(l, r);
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

  std::vector<int> a(n);
  for (int i = 0; i < n; i++)
    std::cin >> a[i];

  quicksort(a.data(), a.data() + n);

  for (int i = 0; i < n; i++)
    std::cout << a[i] << (i == n - 1 ? '\n' : ' ');

  return 0;
}
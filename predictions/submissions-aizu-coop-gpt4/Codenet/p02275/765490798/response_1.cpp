#include <iostream>
#include <vector>
#include <algorithm>

void counting_sort(std::vector<int>& v) {
  int n = v.size();
  int k = *std::max_element(v.begin(), v.end());
  std::vector<int> cnt(k + 1), tmp(v);

  for (int x : v)
    cnt[x]++;

  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];

  for (int i = n - 1; i >= 0; i--) {
    v[cnt[tmp[i]] - 1] = tmp[i];  // arrays are zero-indexed
    cnt[tmp[i]]--;
  }
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> A(n);
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  counting_sort(A);

  for (int i = 0; i < n; i++) {
    std::cout << A[i];
    if (i != n - 1)
      std::cout << ' ';
  }
  std::cout << '\n';

  return 0;
}
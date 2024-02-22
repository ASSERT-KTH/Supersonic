#include <iostream>
#include <vector>
#include <algorithm>

void counting_sort(std::vector<int>& v) {
  int n = v.size();
  int k = *std::max_element(v.begin(), v.end());

  std::vector<int> cnt(k + 1, 0);

  for (int x : v)
    cnt[x]++;

  for (int i = 1; i <= k; i++)
    cnt[i] += cnt[i - 1];

  std::vector<int> sorted(n);
  for (int i = n - 1; i >= 0; i--) {
    sorted[cnt[v[i]] - 1] = v[i];
    cnt[v[i]]--;
  }

  v = sorted;
}

int main() {
  int n;
  std::cin >> n;

  std::vector<int> A(n);
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }

  counting_sort(A);

  std::cout << A[0];
  for (int i = 1; i < n; i++) {
    std::cout << " " << A[i];
  }
  std::cout << std::endl;

  return 0;
}
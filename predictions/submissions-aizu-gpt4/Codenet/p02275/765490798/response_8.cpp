#include <iostream>
#include <vector>
#include <algorithm>

void counting_sort(std::vector<int> &v) {
  int max_val = *max_element(v.begin(), v.end());
  std::vector<int> cnt(max_val + 1, 0);

  for (int x : v)
    cnt[x]++;

  int index = 0;
  for (int i = 0; i <= max_val; i++) {
    while (cnt[i]--) {
      v[index++] = i;
    }
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
    if (i != 0) {
      std::cout << " ";
    }
    std::cout << A[i];
  }
  std::cout << "\n";

  return 0;
}
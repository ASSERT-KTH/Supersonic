#include <iostream>
#include <vector>
#include <algorithm>

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

void counting_sort(std::vector<int> &v) {
  int n = v.size(), k = *std::max_element(v.begin(), v.end());
  std::vector<int> cnt(k + 1), tmp(v);
  cnt[0]--;
  for (int x : v)
    cnt[x]++;
  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
  for (int i = n - 1; i >= 0; i--) {
    v[cnt[tmp[i]]] = tmp[i];
    cnt[tmp[i]]--;
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<int> A(n);
  for (int i = 0; i < n; i++) {
    std::cin >> A[i];
  }
  
  counting_sort(A);

  std::cout << A[0];
  for (int i = 1; i < A.size(); i++) {
    std::cout << " " << A[i];
  }
  std::cout << std::endl;
  
  return 0;
}
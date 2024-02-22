#include <iostream>
#include <vector>
#include <algorithm>

template <class T>
bool chmax(T &a, const T &b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
bool chmin(T &a, const T &b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

void counting_sort(std::vector<int> &v) {
  int n = v.size(), k = *std::max_element(v.begin(), v.end());
  std::vector<int> cnt(k + 1);
  cnt[0]--;
  for (int x : v)
    cnt[x]++;
  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
  std::vector<int> res(n);
  for (int i = n - 1; i >= 0; i--) {
    res[--cnt[v[i]]] = v[i];
  }
  v = res;
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
  for (int i = 1; i < A.size(); i++) {
    std::cout << " " << A[i];
  }
  std::cout << std::endl;
  return 0;
}
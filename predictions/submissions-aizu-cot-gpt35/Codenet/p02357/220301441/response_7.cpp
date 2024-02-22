#include <algorithm>
#include <iostream>
#include <vector>

template <typename T>
class StaticRMQ {
  T *a;
  std::vector<std::vector<int>> table;

public:
  StaticRMQ(std::vector<T> &array) {
    int n = array.size();
    a = new T[n];
    std::copy(array.begin(), array.end(), a);
    table.resize(n, std::vector<int>(log2(n) + 1));

    for (int i = 0; i < n; ++i) {
      table[i][0] = i;
    }

    for (int j = 1; (1 << j) <= n; ++j) {
      for (int i = 0; (i + (1 << j) - 1) < n; ++i) {
        if (a[table[i][j - 1]] < a[table[i + (1 << (j - 1))][j - 1]]) {
          table[i][j] = table[i][j - 1];
        } else {
          table[i][j] = table[i + (1 << (j - 1))][j - 1];
        }
      }
    }
  }

  T operator()(int begin, int end) {
    int k = log2(end - begin + 1);
    if (a[table[begin][k]] <= a[table[end - (1 << k) + 1][k]]) {
      return a[table[begin][k]];
    } else {
      return a[table[end - (1 << k) + 1][k]];
    }
  }
};

int main(void) {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  int n, l;
  std::cin >> n >> l;
  std::vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
  }
  StaticRMQ<int> S(a);
  std::cout << S(0, l);
  for (int i = 1; i < n - l + 1; ++i) {
    std::cout << " " << S(i, i + l);
  }
  std::cout << "\n";
  return 0;
}
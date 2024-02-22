#include <iostream>
#include <vector>
#include <numeric>
#include <cstring>

const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;

template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &vec) {
  os << "[";
  for (const auto &v : vec) {
    os << v << ",";
  }
  os << "]";
  return os;
}

void solve(int n, int m) {
  std::vector<std::string> e(n);
  std::vector<int> e_sizes(n);
  std::string ts;
  int concatenated_len = 0;
  for (int i = 0; i < n; ++i) {
    std::cin >> e[i];
    e_sizes[i] = e[i].size();
    concatenated_len += e_sizes[i];
  }
  
  for (int i = 0; i < m; ++i) {
    std::string t;
    std::cin >> t;
    ts += t;
  }
  
  std::vector<int> sum_len(1 << n);
  for (int i = 0; i < (1 << n); ++i) {
    for (int j = 0; j < n; ++j) {
      if (((i >> j) & 1) == 0)
        continue;
      sum_len[i] += e_sizes[j];
    }
  }
  
  int max_ts_size = ts.size();
  int max_bits_set = __builtin_popcount(n);
  bool** p = new bool*[max_ts_size];
  for (int i = 0; i < max_ts_size; ++i) {
    p[i] = new bool[1 << max_bits_set];
    memset(p[i], false, (1 << max_bits_set) * sizeof(bool));
  }
  
  std::vector<int*> heads(ts.size());
  for (int i = 0; i < ts.size(); ++i) {
    p[i][0] = true;
    for (int j = 0; j < n; ++j) {
      if (i + e_sizes[j] > ts.size() || memcmp(&e[j][0], &ts[i], e_sizes[j]) != 0)
        continue;
      p[i][1 << j] = true;
      heads[i].push_back(&e_sizes[j]);
    }
  }
  
  int ans = 0;
  for (int i = ts.size() - 1; i >= 0; --i) {
    for (int j = 1; j < (1 << n); ++j) {
      if (p[i][j] || i + sum_len[j] > ts.size())
        continue;
      for (int* k : heads[i]) {
        if (((j >> (k - &e_sizes[0])) & 1) == 0)
          continue;
        int i2 = i + *k;
        if (p[i2][j & (~(1 << (k - &e_sizes[0])))]) {
          p[i][j] = true;
          break;
        }
      }
    }
    if (p[i][(1 << n) - 1])
      ++ans;
  }
  
  std::cout << ans << std::endl;
  
  for (int i = 0; i < max_ts_size; ++i) {
    delete[] p[i];
  }
  delete[] p;
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(10);
  
  for (;;) {
    int n, m;
    std::cin >> n >> m;
    if (n == 0 && m == 0)
      break;
    solve(n, m);
  }
  
  return 0;
}
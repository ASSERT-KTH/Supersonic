#include <iostream>
#include <vector>
using namespace std;

const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;

template <typename T>
ostream &operator<<(ostream &os, const vector<T> &vec) {
  os << "[";
  for (const auto &v : vec) {
    os << v << ",";
  }
  os << "]";
  return os;
}

using i64 = int64_t;

struct sqrt_decomp {
  const int bucket_size = 256;
  int length, bucket_num;
  vector<int> bucket_values;
  vector<int> update, bucket_sum;

  sqrt_decomp(const vector<int> &x)
      : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size),
        bucket_values(x.size()),
        update(bucket_num, 2),
        bucket_sum(bucket_num) {
    for (int i = 0; i < x.size(); ++i) {
      bucket_values[i] = x[i];
      bucket_sum[i / bucket_size] += x[i];
    }
  }

  int sum() {
    int res = 0;
    for (int i = 0; i < bucket_num; ++i) {
      if (update[i] == 2)
        res += bucket_sum[i];
      else
        res += update[i] * bucket_size;
    }
    return res;
  }

  void query(int l, int r, int b) {
    l = max(0, l);
    r = min(length - 1, r);
    int bucket_start = l / bucket_size;
    int bucket_end = r / bucket_size;

    for (int i = bucket_start; i <= bucket_end; i++) {
      if (update[i] < 2) {
        int val = update[i];
        int bucket_start_index = i * bucket_size;
        int bucket_end_index = (i + 1) * bucket_size - 1;

        for (int j = bucket_start_index; j <= bucket_end_index; j++) {
          bucket_values[j] = val;
        }

        bucket_sum[i] = val * bucket_size;
        update[i] = 2;
      }
    }

    for (int i = l; i <= r; i++) {
      bucket_sum[i / bucket_size] -= bucket_values[i];
      bucket_values[i] = b;
      bucket_sum[i / bucket_size] += b;
    }

    if (l <= r) {
      for (int i = bucket_start; i <= bucket_end; i++) {
        update[i] = b;
      }
    }
  }

  int at(int i) {
    int bucket_index = i / bucket_size;
    if (update[bucket_index] < 2)
      return update[bucket_index];
    else
      return bucket_values[i];
  }
};

void solve() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<int> x1, x2;
  for (int i = 0; i < n; i++) {
    x1.push_back(s[i] - '0');
    if (i + 1 < n)
      x2.push_back((s[i] - '0') * (s[i + 1] - '0'));
  }
  sqrt_decomp f(x1), g(x2);
  int f_sum = f.sum();
  int g_sum = g.sum();
  
  for (int i = 0; i < q; i++) {
    int l, r, b;
    cin >> l >> r >> b;
    l--;
    r--;
    f.query(l, r, b);
    if (b == 0)
      g.query(l - 1, r, 0);
    else {
      if (l > 0 && f.at(l - 1))
        l--;
      if (r < n - 1 && f.at(r + 1))
        r++;
      g.query(l, r - 1, 1);
    }
    f_sum = f_sum - f.sum() + g.sum();
    g_sum = g.sum();
    cout << f_sum - g_sum << endl;
  }
}

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(10);
  solve();
  return 0;
}
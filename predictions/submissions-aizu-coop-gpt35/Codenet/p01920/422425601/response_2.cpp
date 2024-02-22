#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;

struct sqrt_decomp {
  const int bucket_size = 256;
  int length, bucket_num;
  vector<int> buckets;
  vector<int> bucket_sum;
  bool updated;

  sqrt_decomp(const vector<int>& x)
      : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size),
        buckets(x.size()),
        bucket_sum(bucket_num),
        updated(false) {
    for (int i = 0; i < x.size(); ++i) {
      buckets[i] = x[i];
      bucket_sum[i / bucket_size] += x[i];
    }
  }

  int sum() {
    if (updated) {
      int res = 0;
      for (int i = 0; i < bucket_num; ++i) {
        res += bucket_sum[i];
      }
      return res;
    } else {
      return accumulate(buckets.begin(), buckets.end(), 0);
    }
  }

  void query(int l, int r, int b) {
    l = max(0, l);
    r = min(length - 1, r);

    int start_bucket = l / bucket_size;
    int end_bucket = r / bucket_size;

    if (b == 0) {
      for (int i = start_bucket; i <= end_bucket; ++i) {
        bucket_sum[i] -= buckets[i];
        buckets[i] = b;
        updated = true;
      }
    } else {
      if (start_bucket == end_bucket) {
        for (int i = l; i <= r; ++i) {
          bucket_sum[start_bucket] -= buckets[i];
          buckets[i] = b;
          bucket_sum[start_bucket] += b;
        }
        updated = true;
      } else {
        for (int i = l; i < (start_bucket + 1) * bucket_size; ++i) {
          bucket_sum[start_bucket] -= buckets[i];
          buckets[i] = b;
          bucket_sum[start_bucket] += b;
        }

        for (int i = start_bucket + 1; i < end_bucket; ++i) {
          bucket_sum[i] = b * bucket_size;
          updated = true;
        }

        for (int i = end_bucket * bucket_size; i <= r; ++i) {
          bucket_sum[end_bucket] -= buckets[i];
          buckets[i] = b;
          bucket_sum[end_bucket] += b;
        }
        
        updated = true;
      }
    }
  }

  int at(int i) {
    return buckets[i];
  }
};

void solve() {
  int n, q;
  string s;
  cin >> n >> s >> q;

  vector<int> x1, x2;
  for (int i = 0; i < n; ++i) {
    x1.push_back(s[i] - '0');
    if (i + 1 < n)
      x2.push_back((s[i] - '0') * (s[i + 1] - '0'));
  }

  sqrt_decomp f(x1), g(x2);

  for (int i = 0; i < q; i++) {
    int l, r, b;
    cin >> l >> r >> b;
    l--;
    r--;

    f.query(l, r, b);

    if (b == 0)
      g.query(l - 1, r, 0);
    else {
      int l_ = l, r_ = r - 1;
      if (0 <= l - 1 && f.at(l - 1))
        --l_;
      if (r + 1 < n && f.at(r + 1))
        ++r_;
      g.query(l_, r_, 1);
    }

    cout << f.sum() - g.sum() << endl;
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
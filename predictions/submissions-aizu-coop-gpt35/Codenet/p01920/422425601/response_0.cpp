#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define rep(i, start, end) for (int i = (start); i < (end); ++i)
#define debug(var) #var << "=" << (var)

struct sqrt_decomp {
  int bucket_size;
  int length;
  int bucket_num;
  vector<int> buckets;
  vector<int> update;
  vector<int> bucket_sum;

  sqrt_decomp(const vector<int>& x)
      : length(x.size()),
        bucket_size(256),
        bucket_num((x.size() + bucket_size - 1) / bucket_size) {
    buckets.reserve(bucket_num * bucket_size);
    update.reserve(bucket_num);
    bucket_sum.reserve(bucket_num);

    for (int i = 0; i < x.size(); ++i) {
      buckets.push_back(x[i]);
      bucket_sum[i / bucket_size] += x[i];
      update[i / bucket_size] = 2;
    }
  }

  int sum() {
    int res = 0;
    rep(i, 0, bucket_num) {
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
        int bucket_sum_update = update[i] - buckets[i];
        buckets[i] = update[i];
        bucket_sum[i] += bucket_sum_update * bucket_size;
        update[i] = 2;
      }
    }

    for (int i = l; i <= r; i++) {
      int bucket_index = i / bucket_size;
      bucket_sum[bucket_index] -= buckets[i];
      buckets[i] = b;
      bucket_sum[bucket_index] += b;
    }

    rep(i, bucket_start, bucket_end + 1) {
      update[i] = b;
    }
  }

  int at(int i) {
    int bucket_index = i / bucket_size;
    if (update[bucket_index] < 2)
      return update[bucket_index];
    else
      return buckets[i];
  }
};

void solve() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  vector<int> x1, x2;
  rep(i, 0, n) {
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
      if (0 <= l - 1 and f.at(l - 1))
        --l_;
      if (r + 1 < n and f.at(r + 1))
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
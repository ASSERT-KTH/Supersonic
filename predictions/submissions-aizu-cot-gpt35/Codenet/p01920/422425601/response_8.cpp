#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int inf = 1e9;

struct sqrt_decomp {
  const int bucket_size = 256;
  int length, bucket_num;
  vector<vector<int>> buckets;
  vector<int> update, bucket_sum;

  sqrt_decomp(const vector<int> &x)
      : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size) {
    buckets.resize(bucket_num);
    update.resize(bucket_num, 2);
    bucket_sum.resize(bucket_num);
    for (int i = 0; i < x.size(); ++i) {
      buckets[i / bucket_size].push_back(x[i]);
      bucket_sum[i / bucket_size] += x[i];
    }
  }

  int sum() {
    int res = 0;
    for (int i = 0; i < bucket_num; ++i) {
      res += bucket_sum[i];
    }
    return res;
  }

  void query(int l, int r, int b) {
    l = max(0, l);
    r = min(length - 1, r);
    while (l % bucket_size != 0 && l <= r) {
      int bucket_index = l / bucket_size;
      bucket_sum[bucket_index] -= buckets[bucket_index][l % bucket_size];
      buckets[bucket_index][l % bucket_size] = b;
      bucket_sum[bucket_index] += b;
      ++l;
    }
    while ((r + 1) % bucket_size != 0 and l <= r) {
      int bucket_index = r / bucket_size;
      bucket_sum[bucket_index] -= buckets[bucket_index][r % bucket_size];
      buckets[bucket_index][r % bucket_size] = b;
      bucket_sum[bucket_index] += b;
      --r;
    }
    if (l > r)
      return;
    int bucket_start = l / bucket_size;
    int bucket_end = r / bucket_size;
    fill(update.begin() + bucket_start, update.begin() + bucket_end + 1, b);
  }

  int at(int i) {
    int bucket_index = i / bucket_size;
    return buckets[bucket_index][i % bucket_size];
  }
};

void solve() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  sqrt_decomp f(vector<int>(s.begin(), s.end()));
  sqrt_decomp g(vector<int>(s.begin(), s.end() - 1));

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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.setf(ios::fixed);
  cout.precision(10);
  solve();
  return 0;
}
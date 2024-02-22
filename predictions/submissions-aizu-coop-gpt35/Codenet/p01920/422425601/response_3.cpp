#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct sqrt_decomp {
  const int bucket_size = 256;
  int length, bucket_num;
  vector<int> buckets;
  vector<int> update;
  int bucket_sum;

  sqrt_decomp(const vector<int>& x)
    : length(x.size()),
      bucket_num((x.size() + bucket_size - 1) / bucket_size),
      buckets(x.size()),
      update(bucket_num, 2),
      bucket_sum(0)
  {
    for (int i = 0; i < x.size(); ++i) {
      buckets[i] = x[i];
      bucket_sum += x[i];
    }
  }

  int sum() {
    return bucket_sum + (update[0] == 2 ? 0 : update[0] * buckets.size());
  }

  void query(int l, int r, int b) {
    l = max(0, l);
    r = min(length - 1, r);

    int start_bucket = l / bucket_size;
    int end_bucket = r / bucket_size;

    for (int i = start_bucket + 1; i < end_bucket; ++i) {
      update[i] = b;
      bucket_sum += b * bucket_size;
    }

    if (start_bucket != end_bucket) {
      while (l % bucket_size != 0 && l <= r) {
        bucket_sum -= buckets[l];
        buckets[l] = b;
        bucket_sum += b;
        ++l;
      }

      while ((r + 1) % bucket_size != 0 and l <= r) {
        bucket_sum -= buckets[r];
        buckets[r] = b;
        bucket_sum += b;
        --r;
      }
    }

    if (l > r)
      return;

    update[start_bucket] = b;
    update[end_bucket] = b;
  }

  int at(int i) {
    if (update[i / bucket_size] < 2)
      return update[i / bucket_size];
    else
      return buckets[i];
  }
};

void solve() {
  int n;
  string s;
  cin >> n >> s;
  vector<int> x1;
  for (int i = 0; i < n; ++i) {
    x1.push_back(s[i] - '0');
  }
  sqrt_decomp f(x1);
  sqrt_decomp g(x1);

  int q;
  cin >> q;
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
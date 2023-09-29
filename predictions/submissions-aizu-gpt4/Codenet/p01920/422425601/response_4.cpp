#include <bits/stdc++.h>
using namespace std;

const int BUCKET_SIZE = 256;
struct sqrt_decomp {
  int length, bucket_num;
  vector<vector<int>> buckets;
  vector<int> update, bucket_sum;

  sqrt_decomp(const vector<int> &x)
      : length(x.size()),
        bucket_num((x.size() + BUCKET_SIZE - 1) / BUCKET_SIZE),
        buckets(bucket_num), update(bucket_num, 2), bucket_sum(bucket_num, 0) {
    for (int i = 0; i < x.size(); ++i) {
      buckets[i / BUCKET_SIZE].push_back(x[i]);
      bucket_sum[i / BUCKET_SIZE] += x[i];
    }
  }

  int sum() {
    int res = 0;
    for (int i = 0; i < bucket_num; ++i) {
      res += (update[i] == 2) ? bucket_sum[i] : update[i] * buckets[i].size();
    }
    return res;
  }

  void query(int l, int r, int b) {
    while (l % BUCKET_SIZE != 0 && l <= r) {
      int bucket_index = l / BUCKET_SIZE;
      if (update[bucket_index] < 2) {
        fill(buckets[bucket_index].begin(), buckets[bucket_index].end(), update[bucket_index]);
        bucket_sum[bucket_index] = update[bucket_index] * buckets[bucket_index].size();
        update[bucket_index] = 2;
      }
      bucket_sum[bucket_index] += b - buckets[bucket_index][l % BUCKET_SIZE];
      buckets[bucket_index][l % BUCKET_SIZE] = b;
      ++l;
    }
    while ((r + 1) % BUCKET_SIZE != 0 && l <= r) {
      int bucket_index = r / BUCKET_SIZE;
      if (update[bucket_index] < 2) {
        fill(buckets[bucket_index].begin(), buckets[bucket_index].end(), update[bucket_index]);
        bucket_sum[bucket_index] = update[bucket_index] * buckets[bucket_index].size();
        update[bucket_index] = 2;
      }
      bucket_sum[bucket_index] += b - buckets[bucket_index][r % BUCKET_SIZE];
      buckets[bucket_index][r % BUCKET_SIZE] = b;
      --r;
    }
    for (int i = l / BUCKET_SIZE; i <= r / BUCKET_SIZE; ++i) {
      update[i] = b;
      bucket_sum[i] = b * buckets[i].size();
    }
  }

  int at(int i) {
    int bucket_index = i / BUCKET_SIZE;
    return (update[bucket_index] < 2) ? update[bucket_index] : buckets[bucket_index][i % BUCKET_SIZE];
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
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
  for (int i = 0; i < q; i++) {
    int l, r, b;
    cin >> l >> r >> b;
    l--; r--;
    f.query(l, r, b);
    if (b == 0)
      g.query(l - 1, r, 0);
    else {
      int l_ = max(0, l - 1), r_ = min(n - 2, r);
      if (f.at(l_ + 1))
        ++l_;
      if (f.at(r_ + 1))
        ++r_;
      g.query(l_, r_, 1);
    }
    cout << f.sum() - g.sum() << '\n';
  }
  return 0;
}
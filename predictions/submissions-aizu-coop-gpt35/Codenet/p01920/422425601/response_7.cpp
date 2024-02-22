#include <iostream>
#include <vector>
using namespace std;

struct sqrt_decomp {
  const int bucket_size = 256;
  int length, bucket_num;
  vector<int> buckets;
  
  sqrt_decomp(const vector<int>& x)
      : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size) {
    buckets.resize(bucket_num * bucket_size);
    for (int i = 0; i < x.size(); ++i) {
      buckets[i] = x[i];
    }
  }
  
  int sum() {
    int res = 0;
    for (int i = 0; i < bucket_num; ++i) {
      res += buckets[i] * bucket_size;
    }
    return res;
  }
  
  void query(int l, int r, int b) {
    l = max(0, l);
    r = min(length - 1, r);
    for (int i = l; i <= r; ++i) {
      buckets[i] = b;
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
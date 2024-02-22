#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct sqrt_decomp {
  const int bucket_size = 256;
  int length, bucket_num;
  vector<vector<int>> buckets;
  vector<int> update, bucket_sum;
  int global_sum;
  
  sqrt_decomp(const vector<int>& x)
    : length(x.size()),
      bucket_num((x.size() + bucket_size - 1) / bucket_size),
      global_sum(0)
  {
    buckets.reserve(bucket_num);
    update.reserve(bucket_num);
    bucket_sum.reserve(bucket_num);
    
    for (int i = 0; i < x.size(); ++i) {
      if (i % bucket_size == 0) {
        buckets.emplace_back();
        update.emplace_back(2);
        bucket_sum.emplace_back(0);
      }
      
      buckets.back().push_back(x[i]);
      bucket_sum.back() += x[i];
      global_sum += x[i];
    }
  }
  
  int sum() {
    return global_sum;
  }
  
  void query(int l, int r, int b) {
    l = max(0, l);
    r = min(length - 1, r);
    
    while (l % bucket_size != 0 && l <= r) {
      int bucket_index = l / bucket_size;
      
      if (buckets[bucket_index][l % bucket_size] != b) {
        global_sum -= buckets[bucket_index][l % bucket_size];
        global_sum += b;
        buckets[bucket_index][l % bucket_size] = b;
      }
      
      ++l;
    }
    
    while ((r + 1) % bucket_size != 0 && l <= r) {
      int bucket_index = r / bucket_size;
      
      if (buckets[bucket_index][r % bucket_size] != b) {
        global_sum -= buckets[bucket_index][r % bucket_size];
        global_sum += b;
        buckets[bucket_index][r % bucket_size] = b;
      }
      
      --r;
    }
    
    if (l > r)
      return;
    
    int start_bucket = l / bucket_size;
    int end_bucket = r / bucket_size;
    
    for (int i = start_bucket; i <= end_bucket; ++i) {
      update[i] = b;
    }
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
  
  vector<int> x1, x2;
  x1.reserve(n);
  x2.reserve(n - 1);
  
  for (int i = 0; i < n; ++i) {
    x1.emplace_back(s[i] - '0');
    
    if (i + 1 < n)
      x2.emplace_back((s[i] - '0') * (s[i + 1] - '0'));
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
    
    cout << f.sum() - g.sum() << '\n';
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
#include <iostream>
#include <vector>
#include <string>
#include <bitset>

using namespace std;

const int bucket_size = 256;

struct sqrt_decomp {
  int length, bucket_num;
  vector<int> buckets;
  vector<int> bucket_sum;
  bitset<bucket_size> update;
  
  sqrt_decomp(const vector<int>& x)
    : length(x.size()),
      bucket_num((x.size() + bucket_size - 1) / bucket_size),
      buckets(x.size(), 0),
      bucket_sum(bucket_num, 0),
      update(bucket_num) {
    for (int i = 0; i < x.size(); ++i) {
      buckets[i] = x[i];
      bucket_sum[i / bucket_size] += x[i];
      update[i / bucket_size] = true;
    }
  }
  
  int sum() {
    int res = 0;
    for (int i = 0; i < bucket_num; ++i) {
      if (update[i])
        res += bucket_sum[i];
      else
        res += buckets[i] * (i + 1 == bucket_num ? length % bucket_size : bucket_size);
    }
    return res;
  }
  
  void query(int l, int r, int b) {
    l = max(0, l);
    r = min(length - 1, r);
    int start_bucket = l / bucket_size;
    int end_bucket = r / bucket_size;
    
    for (int i = start_bucket + 1; i < end_bucket; ++i) {
      update[i] = true;
      bucket_sum[i] = b * bucket_size;
    }
    
    if (start_bucket == end_bucket) {
      for (int i = l; i <= r; ++i) {
        buckets[i] = b;
      }
      bucket_sum[start_bucket] = b * (r - l + 1);
    } else {
      for (int i = l; i < (start_bucket + 1) * bucket_size; ++i) {
        buckets[i] = b;
      }
      bucket_sum[start_bucket] = b * ((start_bucket + 1) * bucket_size - l);
      
      for (int i = end_bucket * bucket_size; i <= r; ++i) {
        buckets[i] = b;
      }
      bucket_sum[end_bucket] = b * (r - end_bucket * bucket_size + 1);
    }
    
    update[start_bucket] = update[end_bucket] = true;
  }
  
  int at(int i) {
    int bucket_index = i / bucket_size;
    return buckets[i];
  }
};

void solve() {
  int n, q;
  string s;
  cin >> n >> s >> q;
  
  vector<int> x1(n, 0), x2(n - 1, 0);
  
  for (int i = 0; i < n; ++i) {
    x1[i] = s[i] - '0';
    if (i + 1 < n)
      x2[i] = (s[i] - '0') * (s[i + 1] - '0');
  }
  
  sqrt_decomp f(x1);
  
  for (int i = 0; i < q; i++) {
    int l, r, b;
    cin >> l >> r >> b;
    l--;
    r--;
    f.query(l, r, b);
    if (b == 0)
      f.query(max(0, l - 1), r, b);
    else
      f.query(max(0, l - 1), min(n - 1, r + 1), b);
    cout << f.sum() << endl;
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
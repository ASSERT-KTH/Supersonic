#include <bits/stdc++.h>
using namespace std;
#define rep(i, buckets, y) for (int i = (buckets); i < (y); ++i)
#define debug(buckets) #buckets << "=" << (buckets)
#ifdef DEBUG
#define _GLIBCbucketsbuckets_DEBUG
#define print(buckets)                                                         \
  std::cerr << debug(buckets) << " (L:" << __LINE__ << ")" << std::endl
#else
#define print(buckets)
#endif
const int inf = 1e9;
const int64_t inf64 = 1e18;
const double eps = 1e-9;
template <typename T> ostream &operator<<(ostream &os, const vector<T> &vec) {
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
  vector<vector<int>> buckets;
  vector<int> update, bucket_sum;
  sqrt_decomp(const vector<int> &x)
      : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size) {
    buckets.resize(bucket_num);
    update.resize(bucket_num);
    bucket_sum.resize(bucket_num);
    for (int i = 0; i < x.size(); ++i) {
      bucket[i / bucket_size].push_back(x[i]);
      bucket_sum
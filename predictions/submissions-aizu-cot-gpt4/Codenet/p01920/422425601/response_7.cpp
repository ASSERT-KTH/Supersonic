#include <iostream>
#include <vector>

struct sqrt_decomp {
  const int bucket_size = 256;
  int length, bucket_num;
  std::vector<std::vector<int>> buckets;
  std::vector<int> update, bucket_sum;
  sqrt_decomp(const std::vector<int> &x)
      : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size) {
    buckets.resize(bucket_num);
    update.resize(bucket_num);
    bucket_sum.resize(bucket_num);
    for (int i = 0; i < x.size(); ++i) {
      buckets[i / bucket_size].push_back(x[i]);
      bucket_sum[i / bucket_size] += x[i];
      update[i / bucket_size] = 2;
    }
  }
  // other member functions...
};

int main() {
  std::cin.tie(0);
  std::ios::sync_with_stdio(false);
  std::cout.setf(std::ios::fixed);
  std::cout.precision(10);
  // function calls...
  return 0;
}
// ...
struct sqrt_decomp {
  const int bucket_size = 256;
  int length, bucket_num;
  vector<int> elements; // Use a single vector to store elements
  vector<int> update, bucket_sum;
  sqrt_decomp(const vector<int> &x)
      : length(x.size()),
        bucket_num((x.size() + bucket_size - 1) / bucket_size),
        elements(x.begin(), x.end()) { // Initialize elements with x
    update.resize(bucket_num);
    bucket_sum.resize(bucket_num);
    for (int i = 0; i < x.size(); ++i) {
      bucket_sum[i / bucket_size] += x[i];
      update[i / bucket_size] = 2;
    }
  }
  // ...
  void query(int l, int r, int b) {
    l = max(0, l);
    r = min(length - 1, r);
    int start_bucket = l / bucket_size;
    int end_bucket = r / bucket_size;
    for (int i = start_bucket; i <= end_bucket; ++i) {
      int bucket_start = i * bucket_size;
      int bucket_end = min(bucket_start + bucket_size - 1, length - 1);
      if (i == start_bucket) bucket_start = l;
      if (i == end_bucket) bucket_end = r;
      if (update[i] < 2) {
        int old_bucket_sum = bucket_sum[i];
        bucket_sum[i] = update[i] * (bucket_end - bucket_start + 1);
        int total_change = bucket_sum[i] - old_bucket_sum;
        for (int j = bucket_start; j <= bucket_end; ++j) {
          elements[j] = update[i];
        }
      } else {
        int old_bucket_sum = bucket_sum[i];
        bucket_sum[i] += b * (bucket_end - bucket_start + 1);
        int total_change = bucket_sum[i] - old_bucket_sum;
        for (int j = bucket_start; j <= bucket_end; ++j) {
          elements[j] = b;
        }
      }
      update[i] = b;
    }
  }
  // ...
};
// ...
// Previously included code...
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
      buckets[i / bucket_size].push_back(x[i]);
      bucket_sum[i / bucket_size] += x[i];
      update[i / bucket_size] = 2;
    }
  }
  int sum() {
    int res = 0;
    for (int i = 0; i < bucket_num; ++i) {
      if (update[i] == 2)
        res += bucket_sum[i];
      else
        res += update[i] * buckets[i].size();
    }
    return res;
  }
  void query(int l, int r, int b) {
    l = max(0, l);
    r = min(length - 1, r);
    int start_bucket = l / bucket_size;
    int end_bucket = r / bucket_size;
    for (int i = start_bucket; i <= end_bucket; i++) {
      if (update[i] < 2) {
        for (auto &a : buckets[i])
          a = update[i];
        bucket_sum[i] = update[i] * buckets[i].size();
        update[i] = 2;
      }
      int start_index = (i == start_bucket) ? l % bucket_size : 0;
      int end_index = (i == end_bucket) ? r % bucket_size : (buckets[i].size() - 1);
      for (int j = start_index; j <= end_index; j++) {
        bucket_sum[i] -= buckets[i][j];
        buckets[i][j] = b;
        bucket_sum[i] += b;
      }
    }
  }
  int at(int i) {
    int bucket_index = i / bucket_size;
    if (update[bucket_index] < 2)
      return update[bucket_index];
    else
      return buckets[bucket_index][i % bucket_size];
  }
};
// Rest of the code...
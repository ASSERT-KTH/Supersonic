#include <bits/stdc++.h>
using namespace std;
class suffix_array {
  void create_begin_bucket(vector<int> &v, vector<int> &bucket) {
    fill(bucket.begin(), bucket.end(), 0);
    for (int i = 0; i < v.size(); i++)
      bucket[v[i]]++;
    int sum = 0;
    for (int i = 0; i < bucket.size(); i++) {
      bucket[i] += sum;
      swap(sum, bucket[i]);
    }
  }
  void create_end_bucket(vector<int> &v, vector<int> &bucket) {
    fill(bucket.begin(), bucket.end(), 0);
    for (int i = 0; i < v.size(); i++)
      bucket[v[i]]++;
    for (int i = 1; i < bucket.size(); i++)
      bucket[i] += bucket[i - 1];
  }
  void induced_sort(vector<int> &v, vector<int> &sa, int mv,
                    vector<int> &bucket, vector<int> &is_l) {
    create_begin_bucket(v, bucket);
    for (int i = 0; i < v.size(); i++)
      if (sa[i] > 0 && is_l[sa[i] - 1])
        sa[bucket[v[sa[i] - 1]]++] = sa[i] - 1;
  }
  void invert_induced_sort(vector<int> &v, vector<int> &sa, int mv,
                         vector<int> &bucket, vector<int> &is_l) {
    create_
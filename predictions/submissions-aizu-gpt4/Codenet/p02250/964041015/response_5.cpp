#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <cassert>

using namespace std;

class suffix_array {
  vector<int> build_buckets(vector<int> &v, bool end) {
    vector<int> bucket(*max_element(v.begin(), v.end()) + 1, 0);
    for (int i = 0; i < v.size(); i++)
      bucket[v[i]]++;
    int sum = 0;
    for (int i = 0; i < bucket.size(); i++) {
      sum += bucket[i];
      bucket[i] = end ? sum : sum - bucket[i];
    }
    return bucket;
  }

  void induced_sort(vector<int> &v, vector<int> &sa, vector<int> &is_l, vector<int> &bucket, vector<int> &is_lms, int end) {
    fill(sa.begin(), sa.end(), -1);
    for (int i = 0; i < v.size(); ++i)
      if (is_lms[i])
        sa[--bucket[v[i]]] = i;
    for (int i = 0; i < v.size(); ++i)
      if (sa[i] > 0 && !is_l[sa[i] - 1])
        sa[bucket[v[sa[i] - 1] - 1]++] = sa[i] - 1;
    fill(bucket.begin(), bucket.end(), 0);
    for (int i = 0; i < v.size(); ++i)
      bucket[v[i]]++;
    int sum = 0;
    for (int i = 0; i < bucket.size(); ++i) {
      sum += bucket[i];
      bucket[i] = sum - bucket[i];
    }
    for (int i = v.size() - 1; i >= 0; --i)
      if (sa[i] > 0 && is_l[sa[i] - 1])
        sa[--bucket[v[sa[i] - 1]]] = sa[i] - 1;
  }

  vector<int> sa_is(vector<int> v, int mv) {
    vector<int> is_l(v.size()), bucket(mv + 1), is_lms(v.size(), 0), sa(v.size(), -1);
    is_l[v.size() - 1] = 0;
    for (int i = v.size() - 2; i >= 0; i--)
      is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
    for (int i = 1; i < v.size(); ++i)
      if (is_l[i - 1] && !is_l[i])
       is_lms[i] = 1;
    induced_sort(v, sa, is_l, bucket, is_lms, mv);
    int cur = 0, prev = -1;
    for (int i = 0; i < v.size(); ++i)
      if (is_lms[sa[i]]) {
        bool diff = false;
        for (int d = 0; d < v.size(); ++d) {
          if (prev == -1 || v[sa[i] + d] != v[prev + d] || is_l[sa[i] + d] != is_l[prev + d]) {
            diff = true;
            break;
          } else if (d > 0 && is_lms[sa[i] + d])
            break;
        }
        if (diff) {
          cur++;
          prev = sa[i];
        }
        sa[i] = cur;
      } else
        sa[i] = 0;
    vector<int> s1(sa.size());
    for (int i = 0; i < sa.size(); ++i)
      if (sa[i])
        s1[--cur] = i;
    return sa_is(s1, cur);
  }

  void construct_lcp() {
    lcp.resize(s.size());
    rank.resize(s.size() + 1);
    int n = s.size();
    for (int i = 0; i <= n; i++)
      rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
      int j = sa[rank[i] - 1];
      if (h > 0)
        h--;
      for (; j + h < n && i + h < n; h++) {
        if (s[j + h] != s[i + h])
          break;
      }
      lcp[rank[i] - 1] = h;
    }
  }

public:
  string s;
  vector<int> sa, lcp, rank;
  void init(string &t) {
    s = t;
    vector<int> s1(s.size() + 1, 0);
    for (int i = 0; i < s.size(); ++i) s1[i] = s[i];
    sa = sa_is(s1, 256);
    construct_lcp();
  }
  suffix_array(string &t) { init(t); }
  suffix_array() {}
  bool contain(string &t) {
    int lb = 0, ub = s.size();
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (s.compare(sa[mid], t.size(), t) < 0)
        lb = mid;
      else
        ub = mid;
    }
    return s.compare(sa[ub], t.size(), t) == 0;
  }
};

int main() {
  string s;
  cin >> s;
  suffix_array sa(s);
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    cout << sa.contain(t) << endl;
  }
  return 0;
}
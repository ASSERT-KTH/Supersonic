#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class suffix_array {
  void create_begin_bucket(std::vector<int>& v, int mv, std::vector<int>& bucket) {
    for (int i = 0; i < v.size(); i++) {
      bucket[v[i]]++;
    }
    int sum = 0;
    for (int i = 0; i <= mv; i++) {
      sum += bucket[i];
      bucket[i] = sum - bucket[i];
    }
  }
  void create_end_bucket(std::vector<int>& v, int mv, std::vector<int>& bucket) {
    for (int i = 0; i < v.size(); i++) {
      bucket[v[i]]++;
    }
    for (int i = 1; i <= mv; i++) {
      bucket[i] += bucket[i - 1];
    }
  }
  void induced_sort(std::vector<int>& v, std::vector<int>& sa, int mv,
                    std::vector<int>& bucket, std::vector<int>& is_l) {
    create_begin_bucket(v, mv, bucket);
    for (int i = 0; i < v.size(); i++) {
      if (sa[i] > 0 && is_l[sa[i] - 1]) {
        sa[bucket[v[sa[i] - 1]]++] = sa[i] - 1;
      }
    }
  }
  void invert_induced_sort(std::vector<int>& v, std::vector<int>& sa, int mv,
                           std::vector<int>& bucket, std::vector<int>& is_l) {
    create_end_bucket(v, mv, bucket);
    for (int i = v.size() - 1; i >= 0; i--) {
      if (sa[i] > 0 && !is_l[sa[i] - 1]) {
        sa[--bucket[v[sa[i] - 1]]] = sa[i] - 1;
      }
    }
  }
  std::vector<int> sa_is(std::vector<int> v, int mv) {
    if (v.size() == 1) {
      return std::vector<int>(1, 0);
    }
    std::vector<int> is_l(v.size());
    std::vector<int> bucket(mv + 1);
    std::vector<int> sa(v.size(), -1);
    is_l[v.size() - 1] = 0;
    for (int i = v.size() - 2; i >= 0; i--) {
      is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
    }
    create_end_bucket(v, mv, bucket);
    for (int i = 0; i < v.size(); i++) {
      if (is_lms(i)) {
        sa[--bucket[v[i]]] = i;
      }
    }
    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);
    int cur = 0;
    std::vector<int> order(v.size());
    for (int i = 0; i < v.size(); i++) {
      if (is_lms(i)) {
        order[i] = cur++;
      }
    }
    std::vector<int> next_v(cur);
    cur = -1;
    int prev = -1;
    for (int i = 0; i < v.size(); i++) {
      if (!is_lms(sa[i])) {
        continue;
      }
      bool diff = false;
      for (int d = 0; d < v.size(); d++) {
        if (prev == -1 || v[sa[i] + d] != v[prev + d] ||
            is_l[sa[i] + d] != is_l[prev + d]) {
          diff = true;
          break;
        } else if (d > 0 && is_lms(sa[i] + d)) {
          break;
        }
      }
      if (diff) {
        cur++;
        prev = sa[i];
      }
      next_v[order[sa[i]]] = cur;
    }
    std::vector<int> re_order(next_v.size());
    for (int i = 0; i < v.size(); i++) {
      if (is_lms(i)) {
        re_order[order[i]] = i;
      }
    }
    std::vector<int> next_sa = sa_is(next_v, cur);
    create_end_bucket(v, mv, bucket);
    for (int i = 0; i < sa.size(); i++) {
      sa[i] = -1;
    }
    for (int i = next_sa.size() - 1; i >= 0; i--) {
      sa[--bucket[v[re_order[next_sa[i]]]]] = re_order[next_sa[i]];
    }
    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);
    return sa;
  }
  std::vector<int> sa_is(std::string& s) {
    std::vector<int> v(s.size() + 1);
    for (int i = 0; i < s.size(); i++) {
      v[i] = s[i];
    }
    return sa_is(v, *std::max_element(v.begin(), v.end()));
  }
  void construct_lcp() {
    lcp.resize(s.size());
    rank.resize(s.size() + 1);
    int n = s.size();
    for (int i = 0; i <= n; i++) {
      rank[sa[i]] = i;
    }
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
      int j = sa[rank[i] - 1];
      if (h > 0) {
        h--;
      }
      for (; j + h < n && i + h < n; h++) {
        if (s[j + h] != s[i + h]) {
          break;
        }
      }
      lcp[rank[i] - 1] = h;
    }
  }
  class sparse_table {
    std::vector<std::vector<int>> st;

  public:
    void init(std::vector<int>& v) {
      int b = 0;
      for (int i = 0; (1 << i) < v.size(); i++) {
        b++;
      }
      st.assign(b, std::vector<int>(1 << b));
      for (int i = 0; i < v.size(); i++) {
        st[0][i] = v[i];
      }
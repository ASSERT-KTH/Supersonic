#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

class suffix_array {
  void create_begin_bucket(const std::vector<int>& v, std::vector<int>& bucket) {
    for (int i = 0; i < v.size(); i++)
      bucket[v[i]]++;
    int sum = 0;
    for (int i = 0; i < bucket.size(); i++) {
      int temp = bucket[i];
      bucket[i] = sum;
      sum += temp;
    }
  }

  void create_end_bucket(const std::vector<int>& v, std::vector<int>& bucket) {
    for (int i = 0; i < v.size(); i++)
      bucket[v[i]]++;
    for (int i = 1; i < bucket.size(); i++)
      bucket[i] += bucket[i - 1];
  }

  void induced_sort(const std::vector<int>& v, std::vector<int>& sa, int mv,
                    std::vector<int>& bucket, const std::vector<bool>& is_l) {
    create_begin_bucket(v, bucket);
    for (int i = 0; i < v.size(); i++)
      if (sa[i] > 0 && is_l[sa[i] - 1])
        sa[bucket[v[sa[i] - 1]]++] = sa[i] - 1;
  }

  void invert_induced_sort(const std::vector<int>& v, std::vector<int>& sa, int mv,
                           std::vector<int>& bucket, const std::vector<bool>& is_l) {
    create_end_bucket(v, bucket);
    for (int i = v.size() - 1; i >= 0; i--)
      if (sa[i] > 0 && !is_l[sa[i] - 1])
        sa[--bucket[v[sa[i] - 1]]] = sa[i] - 1;
  }

  std::vector<int> sa_is(const std::vector<int>& v, int mv) {
    if (v.size() == 1)
      return std::vector<int>(1, 0);
    
    std::vector<bool> is_l(v.size());
    std::vector<int> bucket(mv + 1);
    std::vector<int> sa(v.size(), -1);

    auto is_lms = [](int x) -> bool {
      return x > 0 && is_l[x - 1] && !is_l[x];
    };

    is_l[v.size() - 1] = false;
    for (int i = v.size() - 2; i >= 0; i--)
      is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);

    create_end_bucket(v, bucket);
    for (int i = 0; i < v.size(); i++)
      if (is_lms(i))
        sa[--bucket[v[i]]] = i;

    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);

    int cur = 0;
    std::vector<int> order(v.size());
    for (int i = 0; i < v.size(); i++)
      if (is_lms(i))
        order[i] = cur++;

    std::vector<int> next_v(cur);
    for (int i = 0; i < v.size(); i++) {
      if (!is_lms(sa[i]))
        continue;

      bool diff = false;
      for (int d = 0; d < v.size(); d++) {
        if (i > 0 && v[sa[i] + d] != v[sa[i - 1] + d] || is_l[sa[i] + d] != is_l[sa[i - 1] + d]) {
          diff = true;
          break;
        } else if (d > 0 && is_lms(sa[i] + d))
          break;
      }
      
      if (diff)
        cur++;
      
      next_v[order[sa[i]]] = cur;
    }

    std::vector<int> re_order(next_v.size());
    for (int i = 0; i < v.size(); i++)
      if (is_lms(i))
        re_order[order[i]] = i;

    std::vector<int> next_sa = sa_is(next_v, cur);
    create_end_bucket(v, bucket);
    for (int i = 0; i < sa.size(); i++)
      sa[i] = -1;

    for (int i = next_sa.size() - 1; i >= 0; i--)
      sa[--bucket[v[re_order[next_sa[i]]]]] = re_order[next_sa[i]];

    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);

    return sa;
  }

public:
  std::string s;
  std::vector<int> sa, lcp, rank;
  
  suffix_array(const std::string& t) : s(t) {
    std::vector<int> v(s.size() + 1);
    for (int i = 0; i < s.size(); i++)
      v[i] = s[i];
    sa = sa_is(v, *std::max_element(v.begin(), v.end()));
    construct_lcp();
  }

  bool contain(const std::string& t) {
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

  int get_lcp(int i, int j) {
    if (rank[i] > rank[j])
      std::swap(i, j);
    return st.get_min(rank[i], rank[j]);
  }

private:
  class sparse_table {
    std::vector<std::vector<int>> st;

  public:
    sparse_table(const std::vector<int>& v) {
      int b = 0;
      for (; (1 << b) < v.size(); b++);
      st.assign(b, std::vector<int>(1 << b));
      for (int i = 0; i < v.size(); i++)
        st[0][i] = v[i];
      for (int i = 1; i < b; i++) {
        for (int j = 0; j + (1 << i) <= (1 << b); j++) {
          st[i][j] = std::min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
      }
    }

    int get_min(int l, int r) {
      int b = 31 - __builtin_clz(r - l);
      return std::min(st[b][l], st[b][r - (1 << b)]);
    }
  };

  sparse_table st;

  void construct_lcp() {
    lcp.resize(s.size());
    rank.resize(s.size() + 1);
    int n = s.size();
    for (int i = 0; i <= n; i++)
      rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; i++) {
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

class suffix_array {
  void create_bucket(std::vector<int>& v, int mv, bool begin) {
    std::vector<int> bucket(mv + 1, 0);
    for (int i = 0; i < v.size(); i++)
      bucket[v[i]]++;
    int sum = 0;
    for (int i = 0; i < bucket.size(); i++) {
      bucket[i] += sum;
      if (begin)
        swap(sum, bucket[i]);
    }
    if (!begin)
      bucket[0] = 0;
  }

  void induced_sort(std::vector<int>& v, std::vector<int>& sa, int mv,
                    std::vector<int>& is_l) {
    create_bucket(v, mv, true);
    for (int i = 0; i < v.size(); i++)
      if (sa[i] > 0 && is_l[sa[i] - 1])
        sa[create_bucket[v[sa[i] - 1]]++] = sa[i] - 1;
  }

  void invert_induced_sort(std::vector<int>& v, std::vector<int>& sa, int mv,
                           std::vector<int>& is_l) {
    create_bucket(v, mv, false);
    for (int i = v.size() - 1; i >= 0; i--)
      if (sa[i] > 0 && !is_l[sa[i] - 1])
        sa[--create_bucket[v[sa[i] - 1]]] = sa[i] - 1;
  }

  std::vector<int> sa_is(std::vector<int> v, int mv) {
    if (v.size() == 1)
      return std::vector<int>(1, 0);
    std::vector<int> is_l(v.size());
    std::vector<int> sa(v.size(), -1);
    auto is_lms = [&](int x) -> bool {
      return x > 0 && is_l[x - 1] && !is_l[x];
    };
    is_l[v.size() - 1] = 0;
    for (int i = v.size() - 2; i >= 0; i--)
      is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
    create_bucket(v, mv, false);
    for (int i = 0; i < v.size(); i++)
      if (is_lms(i))
        sa[--create_bucket[v[i]]] = i;
    induced_sort(v, sa, mv, is_l);
    invert_induced_sort(v, sa, mv, is_l);
    int cur = 0;
    int prev = -1;
    for (int i = 0; i < v.size(); i++) {
      if (!is_lms(sa[i]))
        continue;
      bool diff = false;
      for (int d = 0; d < v.size(); d++) {
        if (prev == -1 || v[sa[i] + d] != v[prev + d] ||
            is_l[sa[i] + d] != is_l[prev + d]) {
          diff = true;
          break;
        } else if (d > 0 && is_lms(sa[i] + d))
          break;
      }
      if (diff) {
        cur++;
        prev = sa[i];
      }
      v[sa[i]] = cur;
    }
    std::vector<int> re_order(cur);
    cur = -1;
    for (int i = 0; i < v.size(); i++) {
      if (v[sa[i]] != v[sa[i - 1]]) {
        cur++;
      }
      re_order[sa[i]] = cur;
    }
    std::vector<int> next_sa = sa_is(re_order, cur);
    create_bucket(v, mv, false);
    for (int i = 0; i < sa.size(); i++)
      sa[i] = -1;
    for (int i = next_sa.size() - 1; i >= 0; i--)
      sa[--create_bucket[v[re_order[next_sa[i]]]]] = re_order[next_sa[i]];
    induced_sort(v, sa, mv, is_l);
    invert_induced_sort(v, sa, mv, is_l);
    return sa;
  }

  void construct_lcp(std::vector<int>& v, std::vector<int>& sa,
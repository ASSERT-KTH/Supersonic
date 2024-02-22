#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class suffix_array {
  void create_bucket(std::vector<int>& v, std::vector<int>& bucket) {
    bucket.assign(*std::max_element(v.begin(), v.end()) + 1, 0);
    for (int i = 0; i < v.size(); i++) {
      bucket[v[i]]++;
    }
    int sum = 0;
    for (int i = 0; i < bucket.size(); i++) {
      bucket[i] += sum;
      sum = bucket[i];
    }
  }

  void induced_sort(std::vector<int>& v, std::vector<int>& sa, std::vector<int>& bucket, std::vector<int>& is_l) {
    create_bucket(v, bucket);
    for (int i = 0; i < v.size(); i++) {
      if (sa[i] > 0 && is_l[sa[i] - 1]) {
        sa[bucket[v[sa[i] - 1]]++] = sa[i] - 1;
      }
    }
  }

  void invert_induced_sort(std::vector<int>& v, std::vector<int>& sa, std::vector<int>& bucket, std::vector<int>& is_l) {
    create_bucket(v, bucket);
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

    auto is_lms = [&](int x) -> bool {
      return x > 0 && is_l[x - 1] && !is_l[x];
    };

    is_l[v.size() - 1] = 0;
    for (int i = v.size() - 2; i >= 0; i--) {
      is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
    }

    create_bucket(v, bucket);
    for (int i = 0; i < v.size(); i++) {
      if (is_lms(i)) {
        sa[--bucket[v[i]]] = i;
      }
    }

    induced_sort(v, sa, bucket, is_l);
    invert_induced_sort(v, sa, bucket, is_l);

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
        if (prev == -1 || v[sa[i] + d] != v[prev + d] || is_l[sa[i] + d] != is_l[prev + d]) {
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
    create_bucket(v, bucket);
    for (int i = 0; i < sa.size(); i++) {
      sa[i] = -1;
    }
    for (int i = next_sa.size() - 1; i >= 0; i--) {
      sa[--bucket[v[re_order[next_sa[i]]]]] = re_order[next_sa[i]];
    }

    induced_sort(v, sa, bucket, is_l);
    invert_induced_sort(v, sa, bucket, is_l);

    return sa;
  }

public:
  std::string s;
  std::vector<int> sa, lcp;
  void init(std::string& t) {
    s = t;
    std::vector<int> v(s.size() + 1);
    for (int i = 0; i < s.size(); i++) {
      v[i] = s[i];
    }
    sa = sa_is(v, *std::max_element(v.begin(), v.end()));
    // Construct LCP here if needed
  }
  suffix_array(std::string& t) {
    init(t);
  }
  suffix_array() {}
  bool contain(std::string& t) {
    int lb = 0, ub = s.size();
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (s.substr(sa[mid], t.size()) < t) {
        lb = mid;
      } else {
        ub = mid;
      }
    }
    return s.substr(sa[ub], t.size()) == t;
  }
};

int main() {
  std::string s;
  std::cin >> s;
  suffix_array sa(s);
  int q;
  std::cin >> q;
  while (q--) {
    std::string t;
    std::cin >> t;
    std::cout << sa.contain(t) << std::endl;
  }
  return 0;
}
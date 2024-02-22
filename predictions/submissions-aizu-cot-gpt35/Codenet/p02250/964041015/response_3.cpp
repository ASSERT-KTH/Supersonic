#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class suffix_array {
  void create_begin_bucket(const std::vector<int>& v, std::vector<int>& bucket) {
    std::fill(bucket.begin(), bucket.end(), 0);
    for (int i = 0; i < v.size(); i++)
      bucket[v[i]]++;
    int sum = 0;
    for (int i = 0; i < bucket.size(); i++) {
      bucket[i] += sum;
      std::swap(sum, bucket[i]);
    }
  }
  
  void create_end_bucket(const std::vector<int>& v, std::vector<int>& bucket) {
    std::fill(bucket.begin(), bucket.end(), 0);
    for (int i = 0; i < v.size(); i++)
      bucket[v[i]]++;
    for (int i = 1; i < bucket.size(); i++)
      bucket[i] += bucket[i - 1];
  }
  
  void induced_sort(const std::vector<int>& v, std::vector<int>& sa,
                    std::vector<int>& bucket, const std::vector<int>& is_l) {
    create_begin_bucket(v, bucket);
    for (int i = 0; i < v.size(); i++)
      if (sa[i] > 0 && is_l[sa[i] - 1])
        sa[bucket[v[sa[i] - 1]]++] = sa[i] - 1;
  }
  
  void invert_induced_sort(const std::vector<int>& v, std::vector<int>& sa,
                           std::vector<int>& bucket, const std::vector<int>& is_l) {
    create_end_bucket(v, bucket);
    for (int i = v.size() - 1; i >= 0; i--)
      if (sa[i] > 0 && !is_l[sa[i] - 1])
        sa[--bucket[v[sa[i] - 1]]] = sa[i] - 1;
  }
  
  std::vector<int> sa_is(const std::vector<int>& v) {
    if (v.size() == 1)
      return std::vector<int>(1, 0);
    std::vector<int> is_l(v.size());
    std::vector<int> bucket(*std::max_element(v.begin(), v.end()) + 1);
    std::vector<int> sa(v.size(), -1);
    
    auto is_lms = [&](int x) -> bool {
      return x > 0 && is_l[x - 1] && !is_l[x];
    };
    
    is_l[v.size() - 1] = 0;
    for (int i = v.size() - 2; i >= 0; i--)
      is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
    
    create_end_bucket(v, bucket);
    for (int i = 0; i < v.size(); i++)
      if (is_lms(i))
        sa[--bucket[v[i]]] = i;
    
    induced_sort(v, sa, bucket, is_l);
    invert_induced_sort(v, sa, bucket, is_l);
    
    std::vector<int> re_order(v.size());
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
      re_order[sa[i]] = cur;
    }
    
    std::vector<int> next_sa = sa_is(re_order);
    
    create_end_bucket(v, bucket);
    for (int i = next_sa.size() - 1; i >= 0; i--)
      sa[--bucket[v[next_sa[i]]]] = next_sa[i];
    
    induced_sort(v, sa, bucket, is_l);
    invert_induced_sort(v, sa, bucket, is_l);
    
    return sa;
  }
  
  void construct_lcp(const std::string& s) {
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
      if (l >= r)
        return std::numeric_limits<int>::max();
      int b = 31 - __builtin_clz(r - l);
      return std::min(st[b][l], st[b][r - (1 << b)]);
    }
  };
  
  sparse_table st;
  
public:
  std::string s;
  std::vector<int> sa, lcp, rank;
  
  void init(const std::string& t) {
    s = t;
    std::vector<int> v(s.size() + 1);
    for (int i = 0; i < s.size(); i++)
      v[i] = s[i];
    sa = sa_is(v);
    construct_lcp(s);
    st = sparse_table(lcp);
  }
  
  suffix_array(const std::string& t) {
    init(t);
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
    std::cout << sa.contain(t) << '\n';
  }
  return 0;
}
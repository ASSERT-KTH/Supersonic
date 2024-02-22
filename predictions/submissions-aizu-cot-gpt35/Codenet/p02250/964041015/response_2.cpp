#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class suffix_array {
  void create_begin_bucket(vector<int> &v, vector<int> &bucket) {
    int n = v.size();
    bucket.assign(n, 0);
    for (int i = 0; i < n; i++)
      bucket[v[i]]++;
    int sum = 0;
    for (int i = 0; i < n; i++) {
      bucket[i] += sum;
      swap(sum, bucket[i]);
    }
  }
  void create_end_bucket(vector<int> &v, vector<int> &bucket) {
    int n = v.size();
    bucket.assign(n, 0);
    for (int i = 0; i < n; i++)
      bucket[v[i]]++;
    for (int i = 1; i < n; i++)
      bucket[i] += bucket[i - 1];
  }
  void induced_sort(vector<int> &v, vector<int> &sa, int mv,
                    vector<int> &bucket, vector<int> &is_l) {
    create_begin_bucket(v, bucket);
    int n = v.size();
    for (int i = 0; i < n; i++)
      if (sa[i] > 0 && is_l[sa[i] - 1])
        sa[bucket[v[sa[i] - 1]]++] = sa[i] - 1;
  }
  void invert_induced_sort(vector<int> &v, vector<int> &sa, int mv,
                           vector<int> &bucket, vector<int> &is_l) {
    create_end_bucket(v, bucket);
    int n = v.size();
    for (int i = n - 1; i >= 0; i--)
      if (sa[i] > 0 && !is_l[sa[i] - 1])
        sa[--bucket[v[sa[i] - 1]]] = sa[i] - 1;
  }
  vector<int> sa_is(vector<int>& v, int mv) {
    int n = v.size();
    if (n == 1)
      return vector<int>(1, 0);
    vector<int> is_l(n);
    vector<int> bucket(mv + 1);
    vector<int> sa(n, -1);
    auto is_lms = [&](int x) -> bool {
      return x > 0 && is_l[x - 1] && !is_l[x];
    };
    is_l[n - 1] = 0;
    for (int i = n - 2; i >= 0; i--)
      is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
    create_end_bucket(v, bucket);
    for (int i = 0; i < n; i++)
      if (is_lms(i))
        sa[--bucket[v[i]]] = i;
    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);
    int cur = 0;
    vector<int> order(n);
    for (int i = 0; i < n; i++)
      if (is_lms(i))
        order[i] = cur++;
    vector<int> next_v(cur);
    cur = -1;
    int prev = -1;
    for (int i = 0; i < n; i++) {
      if (!is_lms(sa[i]))
        continue;
      bool diff = false;
      for (int d = 0; d < n; d++) {
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
      next_v[order[sa[i]]] = cur;
    }
    vector<int> re_order(next_v.size());
    for (int i = 0; i < n; i++)
      if (is_lms(i))
        re_order[order[i]] = i;
    vector<int> next_sa = sa_is(next_v, cur);
    create_end_bucket(v, bucket);
    for (int i = 0; i < n; i++)
      sa[i] = -1;
    for (int i = next_sa.size() - 1; i >= 0; i--)
      sa[--bucket[v[re_order[next_sa[i]]]]] = re_order[next_sa[i]];
    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);
    return sa;
  }
  void sa_is(string &s) {
    int n = s.size();
    vector<int> v(n + 1);
    for (int i = 0; i < n; i++)
      v[i] = s[i];
    sa = sa_is(v, *max_element(v.begin(), v.end()));
  }
  void construct_lcp() {
    int n = s.size();
    lcp.resize(n);
    rank.resize(n + 1);
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
    vector<vector<int>> st;

  public:
    void init(vector<int> &v) {
      int n = v.size();
      int b = 0;
      while ((1 << b) < n)
        b++;
      st.assign(b, vector<int>(n));
      for (int i = 0; i < n; i++)
        st[0][i] = v[i];
      for (int i = 1; i < b; i++) {
        int m = 1 << i;
        for (int j = 0; j + m <= n; j++) {
          st[i][j] = min(st[i - 1][j], st[i - 1][j + (m >> 1)]);
        }
      }
    }
    int get_min(int l, int r) {
      assert(l < r);
      int b = 31 - __builtin_clz(r - l);
      return min(st[b][l], st[b][r - (1 << b)]);
    }
    sparse_table() {}
    sparse_table(vector<int> &v) { init(v); }
  };
  sparse_table st;

public:
  string s;
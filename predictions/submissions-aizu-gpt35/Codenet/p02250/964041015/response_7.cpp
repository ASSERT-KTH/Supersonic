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
    create_end_bucket(v, bucket);
    for (int i = v.size() - 1; i >= 0; i--)
      if (sa[i] > 0 && !is_l[sa[i] - 1])
        sa[--bucket[v[sa[i] - 1]]] = sa[i] - 1;
  }
  vector<int> sa_is(vector<int> v, int mv) {
    if (v.size() == 1)
      return vector<int>(1, 0);
    vector<int> is_l(v.size());
    vector<int> bucket(mv + 1);
    vector<int> sa(v.size(), -1);
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
    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);
    int cur = 0;
    vector<int> order(v.size());
    for (int i = 0; i < v.size(); i++)
      if (is_lms(i))
        order[i] = cur++;
    vector<int> next_v(cur);
    cur = -1;
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
      next_v[order[sa[i]]] = cur;
    }
    vector<int> re_order(next_v.size());
    for (int i = 0; i < v.size(); i++)
      if (is_lms(i))
        re_order[order[i]] = i;
    vector<int> next_sa = sa_is(next_v, cur);
    create_end_bucket(v, bucket);
    for (int i = 0; i < sa.size(); i++)
      sa[i] = -1;
    for (int i = next_sa.size() - 1; i >= 0; i--)
      sa[--bucket[v[re_order[next_sa[i]]]]] = re_order[next_sa[i]];
    induced_sort(v, sa, mv, bucket, is_l);
    invert_induced_sort(v, sa, mv, bucket, is_l);
    return sa;
  }
  vector<int> sa_is(string &s) {
    vector<int> v(s.size() + 1);
    for (int i = 0; i < s.size(); i++)
      v[i] = s[i];
    v[s.size()] = 0;
    sa = sa_is(v, *max_element(v.begin(), v.end()));
    sa.erase(sa.begin());
    return sa;
  }
  void construct_lcp() {
    lcp.resize(s.size());
    rank.resize(s.size() + 1);
    int n = s.size();
    for (int i = 0; i <= n; i++)
      rank[sa[i]] = i;
    int h = 0;
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
    st.init(lcp);
  }
  class sparse_table {
    vector<vector<int>> st;

  public:
    void init(vector<int> &v) {
      int b;
      for (b = 0; (1 << b) < v.size(); b++)
        ;
      st.assign(b, vector<int>(1 << b));
      for (int i = 0; i < v.size(); i++)
        st[0][i] = v[i];
      for (int i = 1; i < b; i++) {
        for (int j = 0; j + (1 << i) <= (1 << b); j++) {
          st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
        }
      }
    }
    int get_min(int l, int r) {
      assert(l < r);
      int b = 32 - __builtin_clz(r - l) - 1;
      return min(st[b][l], st[b][r - (1 << b)]);
    }
    sparse_table() {}
    sparse_table(vector<int> &v) { init(v); }
  };
  sparse_table st;

public:
  string s;
  vector<int> sa, lcp, rank;
  void init(string &t) {
    s = t;
    sa = sa_is(s);
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
  int get_lcp(int i, int j) {
    if (rank[i] > rank[j])
      swap(i, j);
    return st.get_min(rank[i], rank[j]);
  }
};
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  string s;
  cin >> s;
  suffix_array sa(s);
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    cout << sa.contain(t) << '\n';
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
class suffix_array {
  vector<int> sa, rank, lcp, v;
  string s;

  void create_bucket(vector<int>& bucket, bool end) {
    fill(bucket.begin(), bucket.end(), 0);
    for (auto& i : v) ++bucket[i];
    if (end) {
      for (int i = 1; i < bucket.size(); ++i) bucket[i] += bucket[i - 1];
    } else {
      int sum = 0;
      for (auto& i : bucket) {
        i += sum;
        swap(sum, i);
      }
    }
  }

  void induced_sort(vector<int>& sa, vector<int>& is_l, vector<int>& bucket) {
    create_bucket(bucket, false);
    vector<int> buff(sa.size());
    copy_if(sa.begin(), sa.end(), buff.begin(), [&](int i) { return i > 0 && is_l[i - 1]; });
    for (auto& i : buff) sa[bucket[v[i - 1]]++] = i - 1;
  }

  void invert_induced_sort(vector<int>& sa, vector<int>& is_l, vector<int>& bucket) {
    create_bucket(bucket, true);
    vector<int> buff(sa.rbegin(), sa.rend());
    copy_if(buff.begin(), buff.end(), sa.rbegin(), [&](int i) { return i > 0 && !is_l[i - 1]; });
    for (auto& i : sa) --bucket[v[i]];
  }

  vector<int> sa_is(int mv) {
    if (v.size() == 1) return vector<int>(1, 0);
    vector<int> is_l(v.size()), bucket(mv + 1), sa(v.size(), -1);
    auto is_lms = [&](int x) { return x > 0 && is_l[x - 1] && !is_l[x]; };
    is_l[v.size() - 1] = 0;
    for (int i = v.size() - 2; i >= 0; i--) is_l[i] = v[i] > v[i + 1] || (v[i] == v[i + 1] && is_l[i + 1]);
    create_bucket(bucket, true);
    for (int i = 0; i < v.size(); ++i) if (is_lms(i)) sa[--bucket[v[i]]] = i;
    induced_sort(sa, is_l, bucket);
    invert_induced_sort(sa, is_l, bucket);
    int cur = 0, prev = -1;
    vector<int> order(v.size()), next_v(v.size()), re_order(v.size());
    for (int i = 0; i < v.size(); ++i) if (is_lms(sa[i])) order[sa[i]] = cur++;
    for (int i = 0; i < v.size(); ++i) if (is_lms(i)) re_order[order[i]] = i;
    for (int i = 0; i < v.size(); ++i) {
      if (!is_lms(sa[i])) continue;
      bool diff = false;
      for (int d = 0; d < v.size(); ++d) {
        if (prev == -1 || v[sa[i] + d] != v[prev + d] || is_l[sa[i] + d] != is_l[prev + d]) {
          diff = true;
          break;
        } else if (d > 0 && is_lms(sa[i] + d)) break;
      }
      if (diff) {
        ++cur;
        prev = sa[i];
      }
      next_v[order[sa[i]]] = cur;
    }
    v = move(next_v);
    sa = sa_is(cur);
    create_bucket(bucket, true);
    for (int i = sa.size() - 1; i >= 0; --i) sa[bucket[v[re_order[sa[i]]]]--] = re_order[sa[i]];
    induced_sort(sa, is_l, bucket);
    invert_induced_sort(sa, is_l, bucket);
    return sa;
  }

  void construct_lcp() {
    lcp.resize(s.size());
    rank.resize(s.size() + 1);
    int n = s.size(), h = 0;
    lcp[0] = 0;
    for (int i = 0; i < n; ++i) {
      int j = sa[rank[i] - 1];
      if (h > 0) --h;
      while (j + h < n && i + h < n && s[j + h] == s[i + h]) ++h;
      lcp[rank[i] - 1] = h;
    }
  }

public:
  void init(string& t) {
    s = t;
    v = vector<int>(s.size() + 1);
    for (int i = 0; i < s.size(); ++i) v[i] = s[i];
    sa = sa_is(*max_element(v.begin(), v.end()));
    for (int i = 0; i <= s.size(); ++i) rank[sa[i]] = i;
    construct_lcp();
  }
  suffix_array(string& t) { init(t); }
  bool contain(string& t) {
    int lb = 0, ub = s.size();
    while (ub - lb > 1) {
      int mid = (lb + ub) / 2;
      if (s.compare(sa[mid], t.size(), t) < 0) lb = mid;
      else ub = mid;
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
    cout << sa.contain(t) << '\n';
  }
  return 0;
}
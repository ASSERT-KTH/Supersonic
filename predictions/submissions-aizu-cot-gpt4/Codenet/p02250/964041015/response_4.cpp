#include <bits/stdc++.h>
using namespace std;

class suffix_array {
private:
  string s;
  vector<int> sa, lcp, rank;
  int block_size;
  vector<int> sparse_table;

  // ... rest of the private functions remain unchanged ...

public:
  void init(string &t) {
    s = t;
    sa_is(s);
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
    int l = rank[i], r = rank[j];
    int min_lcp = INT_MAX;
    while (l < r) {
      if (l % block_size == 0 && l + block_size <= r) {
        min_lcp = min(min_lcp, sparse_table[l / block_size]);
        l += block_size;
      } else {
        min_lcp = min(min_lcp, lcp[l]);
        l++;
      }
    }
    return min_lcp;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  suffix_array sa(s);

  int q;
  cin >> q;
  vector<int> results(q);

  for (int i = 0; i < q; i++) {
    string t;
    cin >> t;
    results[i] = sa.contain(t);
  }

  for (int i = 0; i < q; i++) {
    cout << results[i] << "\n";
  }

  return 0;
}
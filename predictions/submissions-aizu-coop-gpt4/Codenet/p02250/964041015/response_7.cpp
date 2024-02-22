#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <cstdio>

using namespace std;

class suffix_array {
  // Optimize function arguments to const reference
  void create_begin_bucket(const vector<int> &v, vector<int> &bucket) { ... }
  void create_end_bucket(const vector<int> &v, vector<int> &bucket) { ... }
  void induced_sort(const vector<int> &v, vector<int> &sa, int mv, vector<int> &bucket, const vector<int> &is_l) { ... }
  void invert_induced_sort(const vector<int> &v, vector<int> &sa, int mv, vector<int> &bucket, const vector<int> &is_l) { ... }
  vector<int> sa_is(vector<int> v, int mv) { ... }
  void construct_lcp() { ... }
  class sparse_table {
    vector<vector<int>> st;
  public:
    void init(const vector<int> &v) { ... }
    int get_min(int l, int r) {
      int b = 32 - __builtin_clz(r - l) - 1;
      return min(st[b][l], st[b][r - (1 << b)]);
    }
    sparse_table() {}
    sparse_table(const vector<int> &v) { init(v); }
  };
  sparse_table st;
public:
  string s;
  vector<int> sa, lcp, rank;
  void init(const string &t) {
    s = t;
    sa_is(s);
    construct_lcp();
  }
  suffix_array(const string &t) { init(t); }
  suffix_array() {}
  bool contain(const string &t) { ... }
  int get_lcp(int i, int j) { ... }
};
signed main() {
  string s;
  // Use faster I/O methods
  cin.sync_with_stdio(false);
  cin.tie(NULL);
  getline(cin, s);
  suffix_array sa(s);
  int q;
  cin >> q;
  cin.ignore();
  while (q--) {
    string t;
    getline(cin, t);
    cout << sa.contain(t) << "\n";
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define MAXN 1000005
class suffix_array {
  int sa[MAXN], lcp[MAXN], rank[MAXN], height[MAXN];

  public:
  string s;
  void init(string &t) {
    s = t;
    construct_sa();
    construct_lcp();
  }

  void construct_sa() {
    // Implementation of constructing suffix array
  }

  void construct_lcp() {
    for (int i=0; i<=s.size(); i++) rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    for (int i=0; i<s.size(); i++) {
      int j = sa[rank[i] - 1];
      if (h > 0) h--;
      while (j + h < s.size() && i + h < s.size()) {
        if (s[j + h] != s[i + h]) break;
        h++;
      }
      lcp[rank[i] - 1] = h;
    }
  }
  
  // Rest of the code
};

signed main() {
  ios_base::sync_with_stdio(false); cin.tie(NULL);
  string s;
  cin >> s;
  suffix_array sa;
  sa.init(s);
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    cout << sa.contain(t) << endl;
  }
  return 0;
}

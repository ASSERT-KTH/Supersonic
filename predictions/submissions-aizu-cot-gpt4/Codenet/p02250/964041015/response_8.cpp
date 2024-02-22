#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cassert>
#include <array>
#include <sstream>

using namespace std;

class suffix_array {
  // ... The rest of the code remains the same ...

  // Update this part
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

int main() {
  std::ios::sync_with_stdio(false);
  string s;
  cin >> s;
  suffix_array sa(s);
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    cout << (sa.contain(t) ? "yes" : "no") << '\n';
  }
  cout << std::flush;
  return 0;
}
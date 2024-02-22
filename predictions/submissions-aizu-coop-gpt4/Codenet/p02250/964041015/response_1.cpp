#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cassert>

using namespace std;

class suffix_array {
  //... Rest of the code remains unchanged ...

public:
  //... Rest of the code remains unchanged ...

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
  ios_base::sync_with_stdio(false); //Use this to speed up the I/O operations
  cin.tie(NULL);

  string s;
  cin >> s;
  suffix_array sa(s);
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    cout << sa.contain(t) << "\n"; //Use "\n" instead of endl to avoid unnecessary flush of the output buffer
  }
  return 0;
}
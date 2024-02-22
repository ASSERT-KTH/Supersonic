#include <bits/stdc++.h>
#include <omp.h>
using namespace std;

// ... other code unchanged ...

void construct_lcp() {
    lcp.resize(s.size());
    rank.resize(s.size() + 1);
    int n = s.size();
    for (int i = 0; i <= n; i++)
      rank[sa[i]] = i;
    int h = 0;
    lcp[0] = 0;
    #pragma omp parallel for
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

// ... other code unchanged ...

signed main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL); 

  string s;
  cin >> s;
  suffix_array sa(s);
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    cout << sa.contain(t) << endl;
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)n; ++i)

typedef map<string, int> msi;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  msi m;
  m["lu"] = 1;
  m["ru"] = 2;
  m["ld"] = 3;
  m["rd"] = 4;
  
  int n, now = 0, next;
  while (cin >> n, n) {
    string s;
    int ans = 0;
    rep(i, n) {
      cin >> s;
      next = m[s];
      if ((now == 1 && next == 2) || (now == 2 && next == 1) || (now == 3 && next == 4) || (now == 4 && next == 3))
        ans++;
      now = next;
    }
    cout << ans << '\n';
  }
  return 0;
}
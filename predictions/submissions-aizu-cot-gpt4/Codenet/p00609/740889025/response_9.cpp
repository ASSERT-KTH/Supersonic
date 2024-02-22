#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v[10000];
int main() {
  ios_base::sync_with_stdio(false); 
  cin.tie(NULL);
  int aN, bN, R;
  while (cin >> aN >> bN >> R, aN) {
    for (int i = 0; i < 10000; i++)
      v[i].clear();
    for (int i = 0; i < aN; i++) {
      int x, y;
      cin >> x >> y;
      v[y].push_back(x);
    }
    for (int i = 0; i < 10000; i++)
      if (!v[i].empty())
        sort(v[i].begin(), v[i].end());
    int D = 4 * R, ans = 0;
    for (int i = 0; i < bN; i++) {
      int x, y;
      cin >> x >> y;
      int p_min = max(-D, -y); // Calculate minimum value for p
      int p_max = min(D, 9999 - y); // Calculate maximum value for p
      for (int p = p_min; p <= p_max; p++) {
        int m_sq = (D - p) * (D + p);
        ans += upper_bound(v[y + p].begin(), v[y + p].end(), x + m_sq) -
               lower_bound(v[y + p].begin(), v[y + p].end(), x - m_sq);
      }
    }
    cout << ans << '\n';
  }
}
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <bitset>
using namespace std;
map<pair<vector<int>, bitset<32>>, int> mp;
string qes[128];
int search(vector<int> &vi, int depth, bitset<32> used, int m, int n) {
  if (mp.count(make_pair(vi, used)))
    return mp[make_pair(vi, used)];
  if (vi.size() > (1 << (m - depth)))
    return 100;
  if (vi.size() == 1)
    return depth;
  int res = 100;
  for (int i = 0; i < m; i++) {
    if (used[i])
      continue;
    vector<int> a, b;
    for (int j = 0; j < vi.size(); j++) {
      if (qes[vi[j]][i] == '0')
        a.push_back(vi[j]);
      else
        b.push_back(vi[j]);
    }
    if (a.empty() || b.empty())
      continue;
    res = min(res, max(search(a, depth + 1, used.set(i), m, n),
                       search(b, depth + 1, used.set(i), m, n)));
  }
  return mp[make_pair(vi, used)] = res;
}
int main() {
  int m, n;
  while (cin >> m >> n, m) {
    for (int i = 0; i < n; i++)
      cin >> qes[i];
    vector<int> vi(n);
    for (int i = 0; i < n; i++)
      vi[i] = i;
    mp.clear();
    cout << search(vi, 0, bitset<32>(0), m, n) << endl;
  }
}
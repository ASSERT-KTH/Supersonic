#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<pair<vector<int>, int>, int> mp;
string qes[128];

int search(vector<int> &vi, int depth, int used, int m, int n) {
  pair<vector<int>, int> p = make_pair(vi, used);
  if (mp.count(p))
    return mp[p];
  if (vi.size() > (1 << (m - depth)))
    return 100;
  if (vi.size() == 1)
    return depth;
  int res = 100;
  vector<int> a, b;
  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1)
      continue;
    a.clear(); b.clear();
    for (int j = 0; j < vi.size(); j++) {
      if (qes[vi[j]][i] == '0')
        a.push_back(vi[j]);
      else
        b.push_back(vi[j]);
    }
    if (a.empty() || b.empty())
      continue;
    res = min(res, max(search(a, depth + 1, used | (1 << i), m, n),
                       search(b, depth + 1, used | (1 << i), m, n)));
  }
  return mp[p] = res;
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
    cout << search(vi, 0, 0, m, n) << endl;
  }
}
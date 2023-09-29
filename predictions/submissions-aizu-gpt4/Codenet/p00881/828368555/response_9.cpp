#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

struct hash_fn
{
    template <class T1, class T2>
    size_t operator () (const pair<T1,T2>& p) const
    {
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};

unordered_map<pair<vector<int>, int>, int, hash_fn> mp;
string qes[128];

int search(vector<int> &vi, int depth, int used, int m, int n) {
  auto it = mp.find(make_pair(vi, used));
  if (it != mp.end())
    return it->second;
  if (vi.size() > (1 << (m - depth)))
    return 100;
  if (vi.size() == 1)
    return depth;
  int res = 100;
  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1)
      continue;
    vector<int> a, b;
    a.reserve(vi.size());
    b.reserve(vi.size());
    for (int j : vi) {
      if (qes[j][i] == '0')
        a.push_back(j);
      else
        b.push_back(j);
    }
    if (a.empty() || b.empty())
      continue;
    res = min(res, max(search(a, depth + 1, used | (1 << i), m, n),
                       search(b, depth + 1, used | (1 << i), m, n)));
  }
  return mp[make_pair(vi, used)] = res;
}

int main() {
  ios::sync_with_stdio(false); // for speed up input/output stream
  cin.tie(nullptr); // for speed up input/output stream
  int m, n;
  while (cin >> m >> n, m) {
    for (int i = 0; i < n; i++)
      cin >> qes[i];
    vector<int> vi(n);
    for (int i = 0; i < n; i++)
      vi[i] = i;
    mp.clear();
    cout << search(vi, 0, 0, m, n) << "\n";
  }
}
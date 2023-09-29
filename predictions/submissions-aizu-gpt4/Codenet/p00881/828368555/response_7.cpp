#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;
unordered_map<string, int> mp;
string qes[128];

string convertVecToString(const vector<int>& vec, int used) {
    string str = "";
    for(auto &v : vec) str += to_string(v);
    str += "_";
    str += to_string(used);
    return str;
}

int search(vector<int> &vi, int depth, int used, int m, int n) {
  string key = convertVecToString(vi, used);
  if (mp.find(key) != mp.end()) return mp[key];
  if (vi.size() > (1 << (m - depth))) return 100;
  if (vi.size() == 1) return depth;
  int res = 100;
  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1) continue;
    vector<int> a, b;
    a.reserve(vi.size());
    b.reserve(vi.size());
    for (int j : vi) {
      if (qes[j][i] == '0') a.push_back(j);
      else b.push_back(j);
    }
    if (a.empty() || b.empty()) continue;
    res = min(res, max(search(a, depth + 1, used | (1 << i), m, n),
                       search(b, depth + 1, used | (1 << i), m, n)));
  }
  return mp[key] = res;
}

int main() {
  int m, n;
  while (cin >> m >> n, m) {
    for (int i = 0; i < n; i++) cin >> qes[i];
    vector<int> vi(n);
    for (int i = 0; i < n; i++) vi[i] = i;
    mp.clear();
    cout << search(vi, 0, 0, m, n) << endl;
  }
}
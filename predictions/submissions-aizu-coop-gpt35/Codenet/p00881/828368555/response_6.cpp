#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

map<pair<int, int>, int> mp;
string qes[128];
int search(int used, int start, int end, int depth, int m) {
  if (mp.find(make_pair(used, end)) != mp.end()) {
    return mp[make_pair(used, end)];
  }
  if ((end - start + 1) > (1 << (m - depth))) {
    return 100;
  }
  if (start == end) {
    return depth;
  }
  int res = 100;
  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1) {
      continue;
    }
    int a = 0, b = 0;
    for (int j = start; j <= end; j++) {
      if (qes[j][i] == '0') {
        a |= (1 << j);
      } else {
        b |= (1 << j);
      }
    }
    if (a == 0 || b == 0) {
      continue;
    }
    res = min(res, max(search(used | (1 << i), start, end, depth + 1, m),
                       search(used | (1 << i), start, end, depth + 1, m)));
  }
  mp.insert(make_pair(make_pair(used, end), res));
  return res;
}

int main() {
  int m, n;
  while (cin >> m >> n, m) {
    for (int i = 0; i < n; i++) {
      cin >> qes[i];
    }
    int used = 0;
    mp.clear();
    cout << search(used, 0, n - 1, 0, m) << endl;
  }
}
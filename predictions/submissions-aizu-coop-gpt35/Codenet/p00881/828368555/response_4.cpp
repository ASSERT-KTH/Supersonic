#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mp;
string qes[128];

int search(vector<int>& vi, int depth, int used, int m, int n, int size) {
  if (mp[size * used + vi[0]] != -1)
    return mp[size * used + vi[0]];

  if (size > (1 << (m - depth)))
    return 100;

  if (size == 1)
    return depth;

  int res = 100;

  for (int i = 0; i < m; i++) {
    if ((used >> i) & 1)
      continue;

    vector<int>::iterator mid = partition(vi.begin(), vi.end(), [&](int j) {
      return (qes[j][i] == '0');
    });

    int a_size = mid - vi.begin();
    int b_size = size - a_size;

    if (a_size == 0 || b_size == 0)
      continue;

    res = min(res, max(search(vi, depth + 1, used | (1 << i), m, n, a_size),
                       search(mid, depth + 1, used | (1 << i), m, n, b_size)));
  }

  mp[size * used + vi[0]] = res;
  return res;
}

int main() {
  int m, n;
  while (cin >> m >> n, m) {
    for (int i = 0; i < n; i++)
      cin >> qes[i];

    vector<int> vi(n);
    for (int i = 0; i < n; i++)
      vi[i] = i;

    int size = n;
    mp.assign((1 << m) * n, -1);

    cout << search(vi, 0, 0, m, n, size) << endl;
  }
}
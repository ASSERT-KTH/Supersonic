#include <iostream>
#include <vector>
#include <map>
using namespace std;

int findParent(vector<int>& p, int x) {
  if (p[x] != x)
    p[x] = findParent(p, p[x]);
  return p[x];
}

void unite(vector<int>& p, vector<int>& r, int x, int y) {
  x = findParent(p, x);
  y = findParent(p, y);
  if (x == y)
    return;
  if (r[x] < r[y])
    swap(x, y);
  r[x] += r[y];
  p[y] = x;
}

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++)
    cin >> a[i];

  vector<int> b(a);
  vector<int> p(n), q(n);
  vector<int> r(n, 1);
  sort(b.begin(), b.end());

  for (int i = 0; i < n; i++) {
    p[a[i]] = i;
    q[b[i]] = i;
  }

  for (int i = 0; i < n; i++)
    unite(p, r, i, p[b[i]]);

  int ans = 0;
  int totalSum = 0;
  int minVal = a[q[0]];
  int k = 0;

  for (int i = 0; i < n; i++) {
    if (p[i] != i)
      continue;
    int m = a[q[i]];
    totalSum += a[q[i]];
    minVal = min(minVal, a[q[i]]);
    k++;
  }

  ans = min(totalSum + minVal * (k - 2), totalSum + minVal + b[0] * (k + 1));

  cout << ans << endl;
  return 0;
}
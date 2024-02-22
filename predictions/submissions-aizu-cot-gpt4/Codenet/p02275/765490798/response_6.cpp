#include "bits/stdc++.h"
using namespace std;

void counting_sort(vector<int> &v) {
  int n = v.size(), k = *max_element(v.begin(), v.end());
  vector<int> cnt(k + 1, 0);

  for (int x : v)
    cnt[x]++;

  int index = 0;
  for (int i = 0; i <= k; i++)
    for (int j = 0; j < cnt[i]; j++)
      v[index++] = i;
}

signed main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) { cin >> A[i]; }
  counting_sort(A);
  for (int i = 0; i < A.size(); i++) {
    if (i > 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
  return 0;
}
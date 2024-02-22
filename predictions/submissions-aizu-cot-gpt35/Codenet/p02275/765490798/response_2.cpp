#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int>& v) {
  int n = v.size(), k = *max_element(v.begin(), v.end());
  vector<int> cnt(k + 1);
  for (int x : v)
    cnt[x]++;
  int idx = 0;
  for (int i = 0; i <= k; i++) {
    while (cnt[i]--)
      v[idx++] = i;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  counting_sort(A);
  cout << A[0];
  for (int i = 1; i < A.size(); i++) {
    cout << " " << A[i];
  }
  cout << endl;
  return 0;
}
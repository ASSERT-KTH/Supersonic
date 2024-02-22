#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int> &v) {
  int n = v.size();
  int k = *max_element(v.begin(), v.end());
  vector<int> cnt(k + 1, 0), tmp(v);
  for (int x : v)
    cnt[x]++;
  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
  for (int i = n - 1; i >= 0; i--) {
    v[cnt[tmp[i]]] = tmp[i];
    cnt[tmp[i]]--;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  int max_value = INT_MIN;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    max_value = max(max_value, A[i]);
  }
  counting_sort(A);
  for (int i = 0; i < A.size(); i++) {
    if(i != 0) cout << " ";
    cout << A[i];
  }
  cout << endl;
  return 0;
}
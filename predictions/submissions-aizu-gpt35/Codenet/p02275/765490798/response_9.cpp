#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<int> &v) {
  int n = v.size(), k = *max_element(v.begin(), v.end());
  vector<int> cnt(k + 1), tmp(v);
  for (int x : v)
    cnt[x]++;
  for (int i = 1; i <= k; i++)
    cnt[i] += cnt[i - 1];
  for (int i = n - 1; i >= 0; i--) {
    v[--cnt[tmp[i]]] = tmp[i];
  }
}

int main() {
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  counting_sort(A);
  for (int i = 0; i < n; i++) {
    cout << A[i];
    if (i != n - 1) {
      cout << " ";
    }
  }
  cout << "\n";
  return 0;
}
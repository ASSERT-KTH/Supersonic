#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int>& v) {
  int n = v.size();
  int k = *max_element(v.begin(), v.end());  // Find the maximum element

  vector<int> cnt(k + 1);  // Reduce the size of cnt to k

  for (int x : v)
    cnt[x]++;

  int idx = 0;  // Use a separate index variable instead of n - 1

  for (int i = 0; i <= k; i++) {  // Iterate up to k instead of k - 1
    while (cnt[i] > 0) {
      v[idx++] = i;
      cnt[i]--;
    }
  }
}

int main() {
  ios::sync_with_stdio(false);  // Improve input/output performance

  int n;
  cin >> n;
  vector<int> A(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }

  counting_sort(A);

  cout << A[0];
  for (int i = 1; i < n; i++) {
    cout << " " << A[i];
  }
  cout << endl;

  return 0;
}
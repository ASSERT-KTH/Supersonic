#include <iostream>
#include <vector>
using namespace std;

void counting_sort(vector<int>& v) {
  int n = v.size();

  // Find the maximum element in the vector
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (v[i] > k) {
      k = v[i];
    }
  }

  // Create and initialize the count array
  vector<int> cnt(k + 1, 0);

  // Perform counting sort
  for (int i = 0; i < n; i++) {
    cnt[v[i]]++;
  }
  for (int i = 1; i <= k; i++) {
    cnt[i] += cnt[i - 1];
  }
  vector<int> sorted(n);
  for (int i = n - 1; i >= 0; i--) {
    sorted[cnt[v[i]] - 1] = v[i];
    cnt[v[i]]--;
  }

  // Copy sorted elements back into the original vector
  v = sorted;
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
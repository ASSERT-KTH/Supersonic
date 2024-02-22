#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void counting_sort(vector<int> &v) {
  int n = v.size();
  int k = *max_element(v.begin(), v.end());
  vector<int> cnt(k + 1), tmp;
  cnt[0]--;
  for (int x : v)
    cnt[x]++;
  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
  for (int i = n - 1; i >= 0; i--) {
    v[cnt[v[i]]] = v[i];
    cnt[v[i]]--;
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> A;
  A.reserve(n);
  for (int i = 0; i < n; i++) {
    int num;
    cin >> num;
    A.push_back(num);
  }
  counting_sort(A);
  cout << A[0];
  for (int i = 1; i < A.size(); i++) {
    cout << " " << A[i];
  }
  cout << endl;
  return 0;
}
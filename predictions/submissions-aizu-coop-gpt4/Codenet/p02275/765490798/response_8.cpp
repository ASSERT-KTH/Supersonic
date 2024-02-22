#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

void counting_sort(vector<int> &v) {
  int n = v.size(), k = *max_element(v.begin(), v.end());
  vector<int> cnt(k + 1);
  cnt[0]--;
  for (int x : v)
    cnt[x]++;
  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
  for (int i = n - 1; i >= 0; i--) {
    cnt[v[i]]--;
    v[cnt[v[i]]] = v[i];
  }
}

int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  for(int i = 0; i < n; i++) {
    cin >> A[i];
  }
  counting_sort(A);
  cout << A[0];
  for(int i = 1; i < A.size(); i++) {
    cout << " " << A[i];
  }
  cout << endl;
  return 0;
}
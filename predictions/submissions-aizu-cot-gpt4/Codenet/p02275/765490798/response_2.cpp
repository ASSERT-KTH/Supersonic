#include "bits/stdc++.h"
using namespace std;
#define rep(i, a, b) for (int i = (a); i < (b); i++)
#define all(c) begin(c), end(c)

const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9 + 7);

void counting_sort(vector<int> &v) {
  int n = v.size(), k = *max_element(all(v));
  vector<int> cnt(k + 1);
  cnt[0]--;
  for (int x : v)
    cnt[x]++;
  for (int i = 0; i < k; i++)
    cnt[i + 1] += cnt[i];
  for (int i = n - 1; i >= 0; i--) {
    int tmp = v[i];
    v[cnt[tmp]] = tmp;
    cnt[tmp]--;
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  
  int n;
  cin >> n;
  vector<int> A(n);
  rep(i, 0, n) { cin >> A[i]; }
  counting_sort(A);
  cout << A[0];
  rep(i, 1, A.size()) { cout << " " << A[i]; }
  cout << endl;
  return 0;
}
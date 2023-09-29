#include <bits/stdc++.h>
using namespace std;

inline void counting_sort(vector<int>& v) {
    int n = v.size();
    int k = *max_element(v.begin(), v.end());
    vector<int> cnt(k + 1), tmp(v);
    cnt[0] = -1;
    for (int x : v) cnt[x]++;
    for (int i = 0; i < k; ++i) cnt[i + 1] += cnt[i];
    for (int i = n - 1; i >= 0; --i) v[cnt[tmp[i]]--] = tmp[i];
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> A(n);
    for (int& a : A) cin >> a;
    counting_sort(A);
    for (int i = 0; i < n; ++i) cout << A[i] << (i + 1 == n ? "\n" : " ");
    return 0;
}
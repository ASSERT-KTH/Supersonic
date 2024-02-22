#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;

    ll a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    sort(a, a + n);

    ll totalSum = 0;
    for (int i = 0; i < n; i++) {
        totalSum += a[i];
    }

    ll curSum = totalSum;
    ll maxSum = totalSum;

    for (int i = 0; i < n; i++) {
        curSum -= a[i];
        maxSum = max(maxSum, (i + 1) * a[i] + curSum);
    }

    cout << maxSum << endl;

    return 0;
}
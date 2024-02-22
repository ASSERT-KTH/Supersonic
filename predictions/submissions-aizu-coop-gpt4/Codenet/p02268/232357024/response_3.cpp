#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }

    int cnt = 0;
    int q, T, left, right, mid;
    cin >> q;

    for (int i = 0; i < q; ++i) {
        cin >> T;
        left = 0;
        right = n;
        mid = (right + left) / 2;

        while (left < right) {
            if (T > S[mid]) {
                left = mid + 1;
            } else if (T < S[mid]) {
                right = mid;
            } else {
                ++cnt;
                break;
            }
            mid = (right + left) / 2;
        }
    }
    cout << cnt << '\n';
    return 0;
}
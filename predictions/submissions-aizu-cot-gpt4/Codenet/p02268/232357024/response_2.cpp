#include <iostream>
#include <vector>
using namespace std;

bool binary_search(vector<int>& S, int n, int T) {
    int left = 0;
    int right = n;
    while (left < right) {
        int mid = (right + left) / 2;
        if (T > S[mid]) {
            left = mid + 1;
        } else if (T < S[mid]) {
            right = mid;
        } else {
            return true;
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; ++i) {
        cin >> S[i];
    }
    int cnt = 0;
    int q;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        int T;
        cin >> T;
        if (binary_search(S, n, T)) {
            ++cnt;
        }
    }
    cout << cnt << "\n";
    return 0;
}
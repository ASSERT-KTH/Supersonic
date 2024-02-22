#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int binary_search(vector<int> &S, int key) {
    int left = 0, right = S.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (S[mid] == key) return 1;
        else if (key < S[mid]) right = mid;
        else left = mid + 1;
    }
    return 0;
}

int main() {
    int n, q, key, sum = 0;
    cin >> n;
    vector<int> S(n);
    for (int i = 0; i < n; i++) cin >> S[i];
    sort(S.begin(), S.end());
    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> key;
        if (binary_search(S, key)) sum++;
    }
    cout << sum << endl;
    return 0;
}